
#include "Node.h"

unsigned int Node::count = 1;

Node::Node(unsigned long long int osmId) : osmId(osmId){}

Node::Node(unsigned long long int osmId, double latitude, double longitude){
	this->osmId = osmId;
    this->id = count++;
    this->latitude = latitude;
    this->longitude = longitude;
}

unsigned int Node::getId() const {
    return id;
}

unsigned long long int Node::getOsmId() const {
	return osmId;
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
	double deltaLat = n2.getLatitude() - this->latitude;
	double deltaLong = n2.getLongitude() - this->longitude;

	double a = sin (deltaLat/2) * sin (deltaLat/2) +
			   cos (this->latitude) * cos(n2.getLatitude()) +
			   sin (deltaLong/2) * sin (deltaLong/2);

	double c = 2 * atan2( sqrt(a), sqrt (1-a));

	return c * EARTH_RADIUS;
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
