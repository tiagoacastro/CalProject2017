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

//		double edgeWeight = (*node1).calculateDistance( (*node2));
//
//		this->graph.addEdge( (*node1), (*node2), edgeWeight);
//
//		if ((*it).isTwoWays())
//		{
//			this->graph.addEdge( (*node2), (*node1), edgeWeight);
//		}

		it++;

	}

}

void BikeCompany::printGraph()
{
		GraphViewer *gv = new GraphViewer(600, 600, true);

		gv->createWindow(600, 600);

		for (unsigned int i = 0; i < graph.getNumVertex();i++)
		{
			gv->addNode(i);
		}

//		gv->rearrange();

		getchar();
}
