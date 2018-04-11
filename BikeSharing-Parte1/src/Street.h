	#pragma once
#include <string>
#include <vector>
#include "Node.h"

using namespace std;

class Street
{

private:
	unsigned int id;
	unsigned long long int osmId;
    double elevation;
    string name;
    bool twoWays;
	vector<Node> nodes;

public:
	static unsigned int count;
	/**
    * Street constructor with id
    * @param osmId 		    street osm id
    */
    explicit Street ( unsigned long long int osmId);
	/**
	 * Street constructor where the slope is randomly calculated
	 * @param elevation int elevation
	 * @param id 		street id
	 * @param name  	street name
	 * @param twoWays	flag that checks if the street is both ways
	 */
	Street(unsigned long long int osmId, string &name, bool twoWays, int elevation);
	/**
	 * Getter which returns the street id
	 * @return id
	 */
    unsigned int getId() const;
	/**
	 * Getter which returns the street Open Street Maps id
	 * @return id
	 */
	unsigned long long int getOsmId() const;
	/**
	 * Getter which returns the street name
	 * @return name
	 */
    const string &getName() const;
	/**
	 * Getter which returns the flag that says if the street is both ways
	 * @return two ways flag
	 */
    bool isTwoWays() const;
	/**
	 * Setter which sets the twoWays flag
	 * @param twoWays  		value to wich the twoWays flag will be changed
	 */
	void setTwoWays(bool twoWays);
    /**
     * Getter which returns the street elevation
     * @return elevation double
     */
    double getElevation();
    /**
     * Setter which sets the street elevation
     * @param elevation double elevation to be set on the Street object
     */
    void setElevation(double elevation);
    /**
     * Overload for the '==' operator for the Street class
     * @param s2			Street to compare
     * @return Returns true if both streets have same id
     */
	bool operator==(const Street &s2) const;
	/**
	 * @brief Adds de node passed as parameter to the Street object
	 * @param n Node to add
	 */
	void addNode(Node &n);
	/**
	 * @brief Getter which returns the vector of Nodes in a Street object
	 * @return vector <Node>
	 */
	vector<Node> &getNodes();
	/**
	 * finds the index of the node with the specified id
	 * @param id   	node id
	 * @return returns node index
	 */
	int findNode(unsigned long long int id);
	/**
     * add street to a node
     * @param i     node index
     * @param id    street id
     */
	void addStreetToNode(int i, int id);
};
