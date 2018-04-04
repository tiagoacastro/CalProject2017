#pragma once
#include <cmath>

class Node {

protected:
    unsigned long id;
    double longitude;
    double latitude;

public:
    /**
    * Node default constructor
    */
    Node() = default;

    Node(unsigned long long int id);
    /**
	 * Node constructor
	 * @param id 		    node id
	 * @param latitude  	node latitude
	 * @param longitude 	node longitude
	 */
    Node(unsigned long long int id, double latitude, double longitude);
    /**
	 * Getter which returns the node id
	 * @return id
	 */
    unsigned int getId() const;
    /**
	 * Getter which returns the node Longitude
	 * @return longitude
	 */
    double getLongitude() const;
    /**
	 * Getter which returns the node Latitude
	 * @return latitude
	 */
    double getLatitude() const;
    /**
     * Overload for the '==' operator for the Node class
     * @param n2			Node to compare
     * @return Returns true if both nodes have same id
     */
	bool operator==(const Node &n2) const;

	/**
	 * Calculates the distance between two nodes.
	 * @param n2			Second node.
	 * @return Distance between both nodes.
	 */
    double calculateDistance (Node &n2);
};

