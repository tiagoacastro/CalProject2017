#pragma once
#include <cmath>
#include <vector>

using namespace std;

#define EARTH_RADIUS 6371e3; //meters

class Node {

protected:
    unsigned int id;
    unsigned long long int osmId;
    double longitude;
    double latitude;
    vector<int> streets;

public:
    static unsigned int count;
    /**
    * Node default constructor
    */
    Node() = default;
    /**
    * Node constructor with id
    * @param osmId 		    node osm id
    */
    explicit Node(unsigned long long int osmId);
    /**
	 * Node constructor
     * @param osmId 		    node osm id
	 * @param latitude  	node latitude
	 * @param longitude 	node longitude
	 */
    Node(unsigned long long int osmId, double latitude, double longitude);
    /**
	 * Getter which returns the node id
	 * @return id
	 */
    unsigned int getId() const;
    /**
	 * Getter which returns the node Open Street Maps id
	 * @return osm id
	 */
    unsigned long long int getOsmId() const;
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
	 * Adds a street ID do the node
	 * @param int    street id to be added
	 */
    void addStreet(int streetID);
    /**
     * Getter for streets id
     * @return      street id vector
     */
    const vector<int> &getStreets() const;
};

