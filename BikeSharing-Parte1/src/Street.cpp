#include "Street.h"


unsigned long long int Street::getId() const {
    return id;
}

void Street::setId(unsigned long long int id) {
    Street::id = id;
}

const string &Street::getName() const {
    return name;
}

void Street::setName(const string &name) {
    Street::name = name;
}

bool Street::isTwoWays() const {
    return twoWays;
}

void Street::setTwoWays(bool twoWays) {
    Street::twoWays = twoWays;
}

double Street::getSlope() const {
    return slope;
}

void Street::setSlope(double slope) {
    Street::slope = slope;
}

Street::Street(unsigned long long int id, string name, bool twoWays) {
    this->id = id;
    this->name = name;
    this->twoWays = twoWays;
}
