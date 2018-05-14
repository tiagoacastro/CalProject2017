#pragma once

#include <vector>
#include "graph.h"
#include "Node.h"
#include "Street.h"
#include "SharingSpot.h"
#include "User.h"
#include "Utilities.h"
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

	/**
	 * Calculated minimum and maximum latitude and longitude and puts teh values on global variables.
	 */
	void setMaxandMin();

	/**
	 * Fills graph with information from street
	 * @param street object from class street from which information is being read and put in graph
	 */
	void addFromStreetToGraph (Street street);

	/**
	 * Draws path from the user's current position to the nearest sharing spot.
	 * @param currentPosition user's current position
	 * @param nearestSharingSpot nearest sharing sport considering user's position.
	 */
	void drawPath (const Node &currentPosition, const Node &nearestSharingSpot);
    /**
     * Checks if a node is also a sharing spot.
     * @param n1 node to be checked.
     * @return 2 if node is a sharing spot with free spots, 1 if node is a sharing spot no free spots, otherwise returns 0.
     */
    int checkIfNodeIsSS (const Node &n1);
	/**
	 * Calculates distance (similarity) between two string
	 * @param pattern 1st string.
	 * @param text 2nd string.
	 * @return distance between strings
	 */
	int editDistance (string pattern, string text);
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
	 * Prints graph using GraphViewer
	 */
	GraphViewer* printGraph();

	/**
	 * Finds the nearest sharing spot and calls function to draw path to it.
	 * @param currentPosition user's current position
	 */
	void getNearestSharingSpot (const Node &currentPosition);
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
     * Finds a street that starts in nodeId1 and ends in nodeId2
     *
     * @param nodeId1 initial node
     * @param nodeId2 final node
     * @return id of the street, or -1 if no street is found
     */
    int findStreetByNodes (int nodeId1, int nodeId2);

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
    /**
     * Check graph's connectivity
     */
    void checkConnectivity();
    /**
     * Searches in vector 'streets' if there is an exact match with streetName.
     * @param streetName name of street.
     * @return -1 if the street is not found, otherwise returns the street's id.
     */
    int exactSearchStreet (string streetName);
    /**
     * Checks if there is a sharing spot in the intersection between the streets given as parameters.
     * @param streetId1 id of street 1.
     * @param streetId2 id of street 2.
     */
    void checkExistenceSharingSpot (int streetId1, int streetId2);
    /**
     * Searches in vector 'streets' and prints the 3 street names more similar with streetName.
     * @param streetName name of the street.
     * @return vector with the id of the streets displayed.
     */
    vector <int> approximateSearchStreet (string streetName);
};
