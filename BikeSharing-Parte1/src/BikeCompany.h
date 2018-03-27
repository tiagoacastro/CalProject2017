#ifndef BIKECOMPANY_H_
#define BIKECOMPANY_H_

#include "Node.h"
#include "Street.h"
#include "SharingSpot.h"
#include <vector>

using namespace std;

class BikeCompany {

private:
	vector<Node> nodes;
	vector<Street> streets;
	vector<SharingSpot> sharingSpots;

public:
	BikeCompany ();
	~BikeCompany ();

	// "Get" functions
	vector<Node> getNodes() {return this->nodes;}
	vector<Street> getStreets() {return this->streets;}
	vector<SharingSpot> getSharingSpots() {return this->sharingSpots;}
};

#endif /* BIKECOMPANY_H_ */
