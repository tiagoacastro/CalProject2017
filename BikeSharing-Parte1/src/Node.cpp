
#include "Node.h"

unsigned int Node::getId() const {
    return id;
}

void Node::setId(unsigned int id) {
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
