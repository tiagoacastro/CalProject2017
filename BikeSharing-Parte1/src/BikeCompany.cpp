#include "BikeCompany.h"

double maxLong = -INF;
double maxLat = - INF;
double minLong = INF;
double minLat = INF;

BikeCompany::BikeCompany(const vector<Node> &nodes, const vector<Street> &streets, const vector<SharingSpot> &sharingSpots, const User &user) :
        nodes(nodes), streets(streets), sharingSpots(sharingSpots), user(user)
{
	createGraph();
}

void BikeCompany::createGraph()
{
	for (const auto &street : streets)
		addFromStreetToGraph (street);
}

void BikeCompany::addFromStreetToGraph (Street street)
{

	for (unsigned int i = 0; i < street.getNodes().size() - 1; i++)
	{
			auto node1 = find (nodes.begin(), nodes.end(), Node(street.getNodes()[i] ) );
			auto node2 = find (nodes.begin(), nodes.end(), Node(street.getNodes()[i+1] ) );

			this->graph.addVertex( (*node1));
			this->graph.addVertex( (*node2));

			double edgeWeight = (*node1).calculateDistance(*node2);

			this->graph.addEdge( (*node1), (*node2), edgeWeight);

			if (street.isTwoWays())
			{
				this->graph.addEdge((*node2), (*node1), edgeWeight);
			}
	}
}

void BikeCompany::setMaxandMin ()
{
	for (const auto &node : nodes)
	{
		if (node.getLongitude() > maxLong)
			maxLong = node.getLongitude();

		if (node.getLongitude() < minLong)
			minLong = node.getLongitude();

		if (node.getLatitude() > maxLat)
			maxLat = node.getLatitude();

		if (node.getLatitude() < minLat)
			minLat = node.getLatitude();
	}
}

GraphViewer * BikeCompany::printGraph()
{
		auto *gv = new GraphViewer(800, 800, false);

		gv->createWindow(800, 800);

		setMaxandMin();

		gv->defineVertexIcon("fdfdf.png");

        for (const auto &node : nodes)
		{
			auto x = (int) (5000 * (node.getLongitude() - minLong) / (maxLong - minLong)) ;
			auto y = (int) (5000 * (node.getLatitude() - minLat) / (maxLat - minLat)) ;
			gv->addNode(node.getId(), 0.3*x, 0.3*(800 - y));
//			gv->addNode(node.getId(), 50*node.getLongitude(), 50*node.getLatitude());

		}

		int id = 0;

		for (const auto &spot : sharingSpots)
		{
			if (spot.isFreeSpot())
				//gv->setVertexIcon(spot.getId(), "C:\\Users\\tiago\\Desktop\\Faculdade\\CAL\\CalProject2017\\BikeSharing-Parte1\\bicycle.png");
				gv->setVertexIcon(spot.getId(), "images/bicycle.png");
			else
				//gv->setVertexIcon(spot.getId(), "C:\\Users\\tiago\\Desktop\\Faculdade\\CAL\\CalProject2017\\BikeSharing-Parte1\\redbicycle.png");
				gv->setVertexIcon(spot.getId(), "images/redbicycle.png");
		}

        for (auto &street : streets)
		{
			for (unsigned int j = 0; j < street.getNodes().size() - 1; j++)
			{
				gv->addEdge(id, street.getNodes()[j].getId(), street.getNodes()[j+1].getId(), EdgeType::UNDIRECTED);
				gv->setEdgeLabel(id, street.getName());
				gv->setEdgeDashed(id,false);
				id++;
			}
		}

		gv->rearrange();

		return gv;
}

void BikeCompany::getNearestSharingSpot (const Node &currentPosition)
{
	vector <SharingSpot> vSpots = this->sharingSpots;
	graph.dijkstraShortestPath(currentPosition);


	int posClosestSpot = -1; //position in vector of closest Sharing Spot
	double closestSpotWeight = INF; //distance from currentPosition to closest Sharing Spot
	double weight = 0;

	for (unsigned int i = 0; i < vSpots.size(); i++)
	{
		SharingSpot elem = vSpots[i];

		if (elem.getId() == currentPosition.getId() && elem.isFreeSpot())
		{
			cout << "You are already in a SharingSpot" << endl;
			return;
		}

		if (!elem.isFreeSpot())
			continue;

		weight = 0;
		graph.getPath(currentPosition, elem, weight); //weight = total distance from currentPosition to elem

		if (weight != 0 && weight < closestSpotWeight) // if weight is less than current minimal distance, then variables are updated
		{
			posClosestSpot = i;
			closestSpotWeight = weight;
		}
	}

	if (posClosestSpot == -1)
	{
		cout << "It wasn't possible to find a sharing spot." << endl;
		return;
	}
	drawPath (currentPosition, vSpots[posClosestSpot]);

}

void BikeCompany::drawPath (const Node &currentPosition, const Node &nearestSharingSpot)
{
	double weight = 0;

	vector <Node> path = graph.getPath (currentPosition, nearestSharingSpot, weight);

	setMaxandMin();

	auto *gv = 	printGraph();

	unsigned int previousNodeId = 0;
	int streetId = 999;

	gv->setVertexIcon(currentPosition.getId(), "images/youarehere.png");

	for (unsigned int i = 0; i < path.size(); i++)
	{
		Node node = path[i];

		if (i > 0)
		{
			gv->addEdge(streetId, previousNodeId, node.getId(), EdgeType::UNDIRECTED);
			gv->setEdgeColor(streetId, "RED");
		}

		previousNodeId = node.getId();
		streetId++;
	}

	gv->rearrange();

	getchar();
}

Street &BikeCompany::findStreet(unsigned long long int osmId){

	int left = 0, right = streets.size()-1;

	while(left <=right){

		int middle = (left + right)/2;
		if (streets.at(middle).getOsmId() < osmId) {
			left = middle + 1;
		}else if(osmId < streets.at(middle).getOsmId()) {
			right = middle -1;
		} else return streets.at(middle);
		}
	}

Node &BikeCompany::findNode(unsigned long long int id){

	int left = 0, right = nodes.size()-1;

	while(left <=right){

		int middle = (left + right)/2;
		if (nodes.at(middle).getOsmId() < id) {
			left = middle + 1;
		}else if(id < nodes.at(middle).getOsmId()) {
			right = middle -1;
		} else return nodes.at(middle);
	}
}

Node &BikeCompany::findNodeById(unsigned int id){

    int left = 0, right = nodes.size()-1;

    while(left <=right){

        int middle = (left + right)/2;
        if (nodes.at(middle).getId() < id) {
            left = middle + 1;
        }else if(id < nodes.at(middle).getId()) {
            right = middle -1;
        } else return nodes.at(middle);
    }
}

Node BikeCompany::getCenter(){
    setMaxandMin();

    Node n;

    n.setLatitude((maxLat+minLat)/2);
    n.setLongitude((maxLong+minLong)/2);

    return n;
}

void BikeCompany::getCheapestSharingSpot (const Node &currentPosition){
    Node n = getCenter();
    long double distanceSum = 0;
    for(auto &node : nodes){
        distanceSum += n.calculateDistance(node);
    }
    double mediumDistance = distanceSum/nodes.size();

    vector<Node> path;

    vector <SharingSpot> vSpots = this->sharingSpots;
    graph.dijkstraShortestPath(currentPosition);

    int posClosestSpot = -1; //position in vector of closest Sharing Spot
    double closestSpotWeight = INF; //distance from currentPosition to closest Sharing Spot
    double weight = 0;

    double elevationSum, elevationMedium;

    for (unsigned int i = 0; i < vSpots.size(); i++)
    {
        elevationSum = 0; elevationMedium = 0;

        SharingSpot elem = vSpots[i];

        if (elem.getId() == currentPosition.getId() && elem.isFreeSpot())
        {
            cout << "You are already in a SharingSpot" << endl;
            return;
        }

        if (!elem.isFreeSpot())
            continue;

        weight = 0;
        path = graph.getPath(currentPosition, elem, weight); //weight = total distance from currentPosition to elem

		if(path.size() >= 2)
        for(int i=0; i<path.size()-1; i++){
            for(const auto &id : path.at(i).getStreets())
                for(const auto &id2 : path.at(i+1).getStreets())
                    if(id == id2){
                        Street s = findStreet(id);
                        if(s.findNode(path.at(i).getOsmId()) < s.findNode(path.at(i+1).getOsmId())){
                            elevationSum += s.getElevation();
                        } else {
                            elevationSum -= s.getElevation();
                        }
                    }
        }

        elevationMedium = elevationSum/path.size();

        if(elevationMedium > 0.2){
            weight*=0.7;
        }

        if(elem.calculateDistance(n) > mediumDistance){
            weight*=0.7;
        }

        if (weight != 0 && weight < closestSpotWeight) // if weight is less than current minimal distance, then variables are updated
        {
            posClosestSpot = i;

            closestSpotWeight = weight;
        }
    }

    if (posClosestSpot == -1)
    {
        cout << "It wasn't possible to find a sharing spot." << endl;
        return;
    }
    drawPath (currentPosition, vSpots[posClosestSpot]);

}

void BikeCompany::checkConnectivity() {

    vector<vector <Node>> res = this->graph.dfs();
    bool connected = true;

    for(int i = 0; i < res.size(); i++) {

        if (res.at(i).size() != this->graph.getNumVertex()) {
            connected = false;
			break;
        }
    }

}
