#include "BikeCompany.h"

BikeCompany::BikeCompany(const vector<Node> &nodes, const vector<Street> &streets, const vector<SharingSpot> &sharingSpots, const User &user) :
        nodes(nodes), streets(streets), sharingSpots(sharingSpots), user(user)
{
	createGraph();
}

void BikeCompany::createGraph()
{

	vector <Node> vNodes = this->nodes;
	vector <Street> vStreets = this->streets;

	vector <Street>::iterator it = vStreets.begin();
	vector <Street>::iterator itend = vStreets.end();

	while (it != itend)
	{
		typename vector <Node>::iterator node1 = find (vNodes.begin(), vNodes.end(), Node( (*it).getInicialNodeID() ) );
		typename vector <Node>::iterator node2 = find (vNodes.begin(), vNodes.end(), Node( (*it).getFinalNodeID() ) );

		this->graph.addVertex( (*node1));
		this->graph.addVertex( (*node2));

		double edgeWeight = (*node1).calculateDistance( (*node2)); //TODO

		this->graph.addEdge( (*node1), (*node2), edgeWeight);

		if ((*it).isTwoWays())
		{
			this->graph.addEdge( (*node2), (*node1), edgeWeight);
		}

		it++;

	}

}

void BikeCompany::printGraph()
{
		GraphViewer *gv = new GraphViewer(600, 600, true);
//		typename vector <Vertex <T> *> vertexs = graph.getVertexSet();

		gv->createWindow(600, 600);

		for (unsigned int i = 0; i < graph.getNumVertex();i++)
		{
			Node node = nodes[i];
			gv->addNode(i, node.getLatitude(), node.getLongitude());
		}

		gv->rearrange();

		getchar();
}

void BikeCompany::getClosestSharingSpot (const Node &currentPosition)
{
	vector <SharingSpot> vSpots = this->sharingSpots;
	graph.dijkstraShortestPath(currentPosition);

	unsigned int posClosestSpot; //position in vector of closest Sharing Spot
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

void BikeCompany::drawPath (const Node &currentPosition, const Node &closestSharingSpot)
{
	double weight = 0;

	vector <Node> path = graph.getPath (currentPosition, closestSharingSpot, weight);

	GraphViewer *gv = new GraphViewer(600, 600, true);

	for (unsigned int i = 0; i < path.size(); i++)
	{
		Node node = path[i];
		gv->addNode(i, node.getLongitude(), node.getLatitude());

		if (i > 0)
			gv->addEdge(i-1, i-1, i, EdgeType::UNDIRECTED);
	}

	getchar();
}
