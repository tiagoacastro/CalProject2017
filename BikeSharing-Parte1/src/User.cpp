#include "User.h"

unsigned int User::getId() const {
    return id;
}

void User::setId(unsigned int id) {
    User::id = id;
}

const string &User::getPayingMethod() const {
    return payingMethod;
}

void User::setPayingMethod(const string &payingMethod) {
    User::payingMethod = payingMethod;
}
