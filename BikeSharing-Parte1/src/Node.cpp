#include "Node.h"

unsigned int Node::count = 1;


Node::Node(double latitude, double longitude){
    this->id = count++;
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

bool Node::operator ==(const Node &n2) const
{
	return id == n2.getId();
}

double Node::calculateDistance (Node &n2)
{
	return sqrt  ( (n2.getLongitude() - getLongitude()) * (n2.getLongitude() - getLongitude()) + (n2.getLatitude() - getLatitude()) * (n2.getLatitude() - getLatitude()));
}

void Node::addStreet(int streetID) {
	this->streets.push_back(streetID);
}

const vector<int> &Node::getStreets() const {
	return streets;
}

void Node::setLongitude(double longitude) {
	Node::longitude = longitude;
}

void Node::setLatitude(double latitude) {
	Node::latitude = latitude;
}

