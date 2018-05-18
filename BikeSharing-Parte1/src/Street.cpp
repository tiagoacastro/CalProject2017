#include "Street.h"
#include "Node.h"

unsigned int Street::count = 1;

Street::Street ()
{
    this-> id = count++;
}

unsigned int Street::getId() const {
    return id;
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

Street::Street(string &name, bool twoWays, int elevation) {
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

int Street::findNode(unsigned long long int osmId){
    for(int i = 0; i < nodes.size(); i++)
        if(nodes.at(i).getId() == osmId)
            return i;
}

void Street::addStreetToNode(int i, int id){
    nodes.at(i).addStreet(id);
}

