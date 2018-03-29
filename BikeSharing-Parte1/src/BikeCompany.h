#ifndef BIKECOMPANY_H_
#define BIKECOMPANY_H_

#include <vector>
#include "graph.h"
#include "Node.h"
#include "Street.h"
#include "SharingSpot.h"
#include "User.h"
using namespace std;

class BikeCompany {

private:
    Graph<Node> graph;
	vector<Node> nodes;
	vector<Street> streets;
	vector<SharingSpot> sharingSpots;
    User user;

public:
	/**
    * BikeCompany constructor
    * @param graph 		    the graph containing all vertexes and edges used for calculating distnces and organizing information
	* @param nodes  		vector with all the nodes from the files (not filtered)
    * @param streets  		vector with all the streets from the files (not filtered)
    * @param sharingSpots	vector with all the sharing spots (some of the nodes that were chosen)
    * @param user			user information
    */
	BikeCompany(const Graph<Node> &graph, const vector<Node> &nodes, const vector<Street> &streets, const vector<SharingSpot> &sharingSpots, const User &user);
	/**
    * Getter which returns the graph
    * @return graph
    */
    Graph<Node> getGraph() {return this->graph;}
	/**
    * Getter which returns a vector with all the nodes
    * @return vector with all the nodes
    */
	vector<Node> getNodes() {return this->nodes;}
	/**
    * Getter which returns a vector with all the streets
    * @return vector with all the streets
    */
	vector<Street> getStreets() {return this->streets;}
	/**
    * Getter which returns a vector with all the sharing spots
    * @return vector with all the sharing spots
    */
	vector<SharingSpot> getSharingSpots() {return this->sharingSpots;}
	/**
    * Getter which returns the user information
    * @return user information
    */
    User getUser() {return this->user;}
};

#endif /* BIKECOMPANY_H_ */
