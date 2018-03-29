#include "BikeCompany.h"

BikeCompany::BikeCompany(const Graph<Node> &graph, const vector<Node> &nodes, const vector<Street> &streets,
                         const vector<SharingSpot> &sharingSpots, const User &user) : graph(graph), nodes(nodes),
                                                                                      streets(streets),
                                                                                      sharingSpots(sharingSpots),
                                                                                      user(user) {}
