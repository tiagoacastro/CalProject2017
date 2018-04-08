#include "SharingSpot.h"

#include <iostream>

SharingSpot::SharingSpot(Node n){
    id = n.getId();
    latitude = n.getLatitude();
    longitude = n.getLongitude();
    freeSpot = true;
}

bool SharingSpot::isFreeSpot() const {
    return freeSpot;
}
