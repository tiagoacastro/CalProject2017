#include "BikeCompany.h"

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

# define M_PI           3.14159265358979323846  /* pi */

void BikeCompany::printGraph()
{
		auto *gv = new GraphViewer(800, 800, false);

		gv->createWindow(600, 600);

		double maxLong=-1000000;
		double maxLat=-100000;
		double minLong=1000000;
		double minLat=1000000;


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
			auto x = (int)(6000 * (node.getLongitude() - minLong) / (maxLong - minLong)) ;
			auto y = (int)(6000 * (node.getLatitude() - minLat) / (maxLat - minLat)) ;
			gv->addNode(node.getId(), x,600 - y);
			gv->setVertexLabel(node.getId(), " ");
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
	cout << "getNearestSharingSpot";

	vector <SharingSpot> vSpots = this->sharingSpots;
	graph.dijkstraShortestPath(currentPosition);

	unsigned int posClosestSpot = 0; //position in vector of closest Sharing Spot
	double closestSpotWeight = INF; //distance from currentPosition to closest Sharing Spot

	for (unsigned int i = 0; i < vSpots.size(); i++)
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

	cout << "drawPath";

	vector <Node> path = graph.getPath (currentPosition, nearestSharingSpot, weight);

	auto *gv = new GraphViewer(600, 600, true);

	gv->createWindow(600, 600);

	for (unsigned int i = 0; i < path.size(); i++)
	{
		Node node = path[i];
		gv->addNode(i, node.getLongitude(), node.getLatitude());

		if (i > 0)
			gv->addEdge(i-1, i-1, i, EdgeType::UNDIRECTED);
	}

	gv->rearrange();

	getchar();
}
