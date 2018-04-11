#pragma once

#include <vector>
#include "graph.h"
#include "Node.h"
#include "Street.h"
#include "SharingSpot.h"
#include "User.h"
#include "graphviewer.h"
#include <algorithm>
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
	* @param nodes  		vector with all the nodes from the files (not filtered)
    * @param streets  		vector with all the streets from the files (not filtered)
    * @param sharingSpots	vector with all the sharing spots (some of the nodes that were chosen)
    * @param user			user information
    */
	BikeCompany(const vector<Node> &nodes, const vector<Street> &streets, const vector<SharingSpot> &sharingSpots, const User &user);
	/**
	 * Fills graph with the vertexs and the edges
	 */
	void createGraph();
	/**
	 * Fills graph with information from street
	 * @param street object from class street from which information is being read and put in graph
	 */
	void addFromStreetToGraph (Street street);
	/**
	 * Prints graph using GraphViewer
	 */

	void setMaxandMin();
	void printGraph();

	/**
	 * Finds the nearest sharing spot and calls function to draw path to it.
	 * @param currentPosition user's current position
	 */
	void getNearestSharingSpot (const Node &currentPosition);

	/**
	 * Draws path from the user's current position to the nearest sharing spot.
	 * @param currentPosition user's current position
	 * @param nearestSharingSpot nearest sharing sport considering user's position.
	 */
	void drawPath (const Node &currentPosition, const Node &nearestSharingSpot);
	/**
    * Getter which returns the graph
    * @return graph
    */
    Graph<Node>& getGraph() {return this->graph;}
	/**
    * Getter which returns a vector with all the nodes
    * @return vector with all the nodes
    */
	vector<Node>& getNodes() {return this->nodes;}
	/**
    * Getter which returns a vector with all the streets
    * @return vector with all the streets
    */
	vector<Street>& getStreets() {return this->streets;}
	/**
    * Getter which returns a vector with all the sharing spots
    * @return vector with all the sharing spots
    */
	vector<SharingSpot>& getSharingSpots() {return this->sharingSpots;}
	/**
    * Getter which returns the user information
    * @return user information
    */
    User getUser() {return this->user;}
	/**
	 * Finds the street with the specified if
	 * @param id	street id
	 * @return	street
	 */
	Street &findStreet(unsigned long long int id);
	/**
   * Finds the node with the specified open street map id
   * @param id  node id
   * @return  node
   */
	Node &findNode(unsigned long long int id);
	/**
   * Finds the node with the specified id
   * @param id  node id
   * @return  node
   */
	Node &findNodeById(unsigned int id);
    /**
     * Returns a node that identifies the center of the graph
     * @return center node
     */
    Node getCenter();
    /**
	 * Finds the cheapest sharing spot and calls function to draw path to it.
	 * @param currentPosition user's current position
     */
    void getCheapestSharingSpot (const Node &currentPosition);

    void checkConnectivity();
};
