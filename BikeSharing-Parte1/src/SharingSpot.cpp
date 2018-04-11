#include "SharingSpot.h"

#include <iostream>

SharingSpot::SharingSpot(Node n){
    id = n.getId();
    osmId = n.getOsmId();
    latitude = n.getLatitude();
    longitude = n.getLongitude();
    streets = n.getStreets();
    int i = rand()%5;

    if (i == 0)
        freeSpot = false;

    else freeSpot = true;

}

bool SharingSpot::isFreeSpot() const {
    return freeSpot;
}
