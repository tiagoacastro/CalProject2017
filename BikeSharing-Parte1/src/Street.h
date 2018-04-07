#pragma once
#include <string>
#include <vector>
#include "Node.h"

using namespace std;

class Street
{

private:
    unsigned long long int id;
    string name;
    bool twoWays;
    double slope;
	vector<Node> nodes;

public:
    explicit Street (unsigned long long int id);
	/**
	 * Street constructor where the slope is randomly calculated
	 * @param id 		street id
	 * @param name  	street name
	 * @param twoWays	flag that checks if the street is both ways
	 */
	Street(unsigned long long int id, string &name, bool twoWays);
	/**
	 * Getter which returns the street id
	 * @return id
	 */
    unsigned long long int getId() const;
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
	 * Getter which returns the street slope
	 * @return slope
	 */
    double getSlope() const;
	/**
	 * Setter which sets the twoWays flag
	 * @param twoWays  		value to wich the twoWays flag will be changed
	 */
	void setTwoWays(bool twoWays);
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
	void addNode(Node n);
	/**
	 * @brief Getter which returns the vector of Nodes in a Street object
	 * @return vector <Node>
	 */
	vector<Node> getNodes();

};
