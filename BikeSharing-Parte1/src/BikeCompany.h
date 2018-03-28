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
    vector<User> users;

public:
	BikeCompany ();
	~BikeCompany ();

	// "Get" functions
    Graph<Node> getGraph() {return this->graph;}
	vector<Node> getNodes() {return this->nodes;}
	vector<Street> getStreets() {return this->streets;}
	vector<SharingSpot> getSharingSpots() {return this->sharingSpots;}
    vector<User> getUsers() {return this->users;}
};

#endif /* BIKECOMPANY_H_ */
