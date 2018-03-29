
#include "Node.h"

Node::Node(unsigned long long int id, double latitude, double longitude){
    this->id = id;
    this->latitude = latitude;
    this->longitude = longitude;
}

unsigned int Node::getId() const {
    return id;
}

double Node::getLongitude() const {
    return longitude;
}

double Node::getLatitude() const {
    return latitude;
}