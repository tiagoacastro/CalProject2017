#include "BikeCompany.h"

BikeCompany::BikeCompany(const vector<Node> &nodes, const vector<Street> &streets, const vector<SharingSpot> &sharingSpots, const vector<Relation> &relations, const User &user) :
        nodes(nodes), streets(streets), sharingSpots(sharingSpots), relations(relations), user(user) {}
