#include "Street.h"

Street::Street (unsigned int id , unsigned long long int osmId): id (id), osmId(osmId)
{
}

unsigned int Street::getId() const {
    return id;
}

unsigned long long int Street::getOsmId() const {
    return osmId;
}

const string &Street::getName() const {
    return name;
}

bool Street::isTwoWays() const {
    return twoWays;
}

double Street::getSlope() const {
    return slope;
}

Street::Street(unsigned int id, unsigned long long int osmId, string &name, bool twoWays) {
    this->osmId = osmId;
    this->id = id;
    this->name = name;
    this->twoWays = twoWays;
}

void Street::setTwoWays(bool twoWays) {
    Street::twoWays = twoWays;
}

bool Street::operator ==(const Street &s2) const
{
	return id == s2.getId();
}

void Street::addNode(Node n) {
    this->nodes.push_back(n);
}

vector<Node> Street::getNodes() {
    return this->nodes;
}
