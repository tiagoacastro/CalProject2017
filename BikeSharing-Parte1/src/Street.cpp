#include "Street.h"

unsigned int Street::count = 1;

Street::Street (unsigned long long int osmId):osmId(osmId)
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

double Street::getElevation() {
    return this->elevation;
}

void Street::setElevation(double elevation) {
    this->elevation = elevation;
}

Street::Street(unsigned long long int osmId, string &name, bool twoWays, int elevation) {
    this->osmId = osmId;
    this->id = count++;
    this->name = name;
    this->twoWays = twoWays;
    this->elevation = elevation;
}

void Street::setTwoWays(bool twoWays) {
    Street::twoWays = twoWays;
}

bool Street::operator ==(const Street &s2) const
{
	return id == s2.getId();
}

void Street::addNode(Node &n) {
    this->nodes.push_back(n);
}

vector<Node> &Street::getNodes() {
    return this->nodes;
}

int Street::findNode(unsigned int id){
    for(int i = 0; i < nodes.size(); ++i)
        if(nodes.at(i).getId() == id)
            return i;
}

void Street::setNodeHeight(int i, double height){
    nodes.at(i).setHeight(height);
}

void Street::setNodeHeightCalculated(int i){
    nodes.at(i).setHeightCalculated(true);
}

