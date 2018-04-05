#include "Street.h"

Street::Street (unsigned long long int id): id (id)
{
}

unsigned long long int Street::getId() const {
    return id;
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

void Street::setInicialNodeID(int n){
    this->inicialNodeID = n;
}

void Street::setFinalNodeID(int n){
    this->finalNodeID = n;
}

int Street::getInicialNodeID() {
    return this->inicialNodeID;
}

int Street::getFinalNodeID() {
    return this->finalNodeID;
}


Street::Street(unsigned long long int id, string name, bool twoWays) {
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
