#pragma once
#include <cmath>
#include <vector>

using namespace std;

class Node {

protected:
    unsigned long long id;
    double longitude;
    double latitude;
    vector<int> streets;

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
    unsigned long long getId() const;
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
    /**
	 * Adds a street do the node
	 * @param street    street to be added
	 */
    void addStreet(int streetID);
};

