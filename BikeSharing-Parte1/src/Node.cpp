
#include "Node.h"

Node::Node(unsigned long long int id, double latitude, double longitude){
    this->id = id;
    this->latitude = latitude;
    this->longitude = longitude;
}

unsigned int Node::getId() const {
    return id;
}

void Node::setId(unsigned long id) {
    Node::id = id;
}

double Node::getLongitude() const {
    return longitude;
}

void Node::setLongitude(double longitude) {
    Node::longitude = longitude;
}

double Node::getLatitude() const {
    return latitude;
}

void Node::setLatitude(double latitude) {
    Node::latitude = latitude;
}
