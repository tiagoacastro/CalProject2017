#include "BikeCompany.h"

double maxLong=-1000000;
double maxLat=-100000;
double minLong=1000000;
double minLat=1000000;

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

void BikeCompany::printGraph()
{
		auto *gv = new GraphViewer(800, 800, false);

		gv->createWindow(800, 800);

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

        for (const auto &node : nodes)
		{
			auto x = (int) (3500 * (node.getLongitude() - minLong) / (maxLong - minLong)) ;
			auto y = (int) (3500 * (node.getLatitude() - minLat) / (maxLat - minLat)) ;
			gv->addNode(node.getId(), x, 800 - y);
		}

		int id = 0;

        for (auto &street : streets)
		{
			for (unsigned int j = 0; j < street.getNodes().size() - 1; j++)
			{
				gv->addEdge(id, street.getNodes()[j].getId(), street.getNodes()[j+1].getId(), EdgeType::UNDIRECTED);
				gv->setEdgeLabel(id, street.getName());
				id++;
			}
		}

		gv->rearrange();

		getchar();
}

void BikeCompany::getNearestSharingSpot (const Node &currentPosition)
{
	vector <SharingSpot> vSpots = this->sharingSpots;
	graph.dijkstraShortestPath(currentPosition);


	unsigned int posClosestSpot = 0; //position in vector of closest Sharing Spot
	double closestSpotWeight = INF; //distance from currentPosition to closest Sharing Spot

	for (unsigned int i = 0; i < 2; i++)
	{
		SharingSpot elem = vSpots[i];

		double weight = 0;
		graph.getPath(currentPosition, elem, weight); //weight = total distance from currentPosition to elem

		if (weight < closestSpotWeight) // if weight is less than current minimal distance, then variables are updated
		{
			posClosestSpot = i;
			closestSpotWeight = weight;
		}
	}
	drawPath (currentPosition, vSpots[posClosestSpot]);

}

void BikeCompany::drawPath (const Node &currentPosition, const Node &nearestSharingSpot)
{
	double weight = 0;

	vector <Node> path = graph.getPath (currentPosition, nearestSharingSpot, weight);

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

	auto *gv = new GraphViewer(800, 800, false);

	gv->createWindow(800, 800);

	unsigned int previousNodeId = 0;

	for (unsigned int i = 0; i < path.size(); i++)
	{
		Node node = path[i];

		auto x = (int) (3500 * (node.getLongitude() - minLong) / (maxLong - minLong)) ;
		auto y = (int) (3500 * (node.getLatitude() - minLat) / (maxLat - minLat)) ;
		gv->addNode(node.getId(), x, 800 - y);

		if (i > 0)
		{
			gv->addEdge(i, previousNodeId, node.getId(), EdgeType::UNDIRECTED);
		}

		previousNodeId = node.getId();

	}

	gv->rearrange();

	getchar();
}

Street &BikeCompany::findStreet(unsigned int id){

    int left = 0, right = streets.size()-1;

    while(left <=right){

        int middle = (left + right)/2;
        if (streets.at(middle).getId() < id) {
            left = middle + 1;
        }else if(id < streets.at(middle).getId()) {
            right = middle -1;
        } else return streets.at(middle);
    }
}

void BikeCompany::calculate(Street &s, int i, double h){
    if(i > 0)
        if(!s.getNodes().at(i-1).isHeightCalculated()){
            s.setNodeHeight(i-1, h - s.getElevation()*s.getNodes().at(i-1).calculateDistance(s.getNodes().at(i)));
            s.setNodeHeightCalculated(i-1);
            for(auto id : s.getNodes().at(i-1).getStreets())
                calculate(findStreet(id), findStreet(id).findNode(s.getNodes().at(i-1).getId()), s.getNodes().at(i-1).getHeight());
        }
    if(i < s.getNodes().size()-1){
        if(!s.getNodes().at(i+1).isHeightCalculated()){
            s.setNodeHeight(i+1, h + s.getElevation()*s.getNodes().at(i+1).calculateDistance(s.getNodes().at(i)));
            s.setNodeHeightCalculated(i+1);
            for(auto id : s.getNodes().at(i+1).getStreets())
                calculate(findStreet(id), findStreet(id).findNode(s.getNodes().at(i+1).getId()), s.getNodes().at(i+1).getHeight());
        }
    }
}

void BikeCompany::calculateHeights(){
    nodes.at(0).setHeight(0);
    nodes.at(0).setHeightCalculated(true);
    int i;

    for(auto id : nodes.at(0).getStreets()){
        i = nodes.at(0).getId();
        calculate(findStreet(id), findStreet(i).findNode(id), 0);
    }
}
