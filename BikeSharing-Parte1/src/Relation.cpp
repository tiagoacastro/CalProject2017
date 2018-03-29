//
// Created by jonas on 29/03/2018.
//

#include "Relation.h"

Relation::Relation(unsigned long long int roadID, unsigned long long int node1ID, unsigned long long int node2ID) {
    this->roadID = roadID;
    this->node1ID = node1ID;
    this->node2ID = node2ID;
}

unsigned long long int Relation::getRoadID() {
    return roadID;
}

unsigned long long int Relation::getNode1ID() {
    return this->node1ID;
}

unsigned long long int Relation::getNode2ID() {
    return this->node2ID;
}