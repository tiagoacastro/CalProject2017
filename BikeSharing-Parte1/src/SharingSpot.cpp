#include "SharingSpot.h"

#include <iostream>

SharingSpot::SharingSpot(Node n){
    id = n.getId();
    latitude = n.getLatitude();
    longitude = n.getLongitude();

    int i = rand()%5;

    if (i == 0)
        freeSpot = true;
    else freeSpot = false;

}

bool SharingSpot::isFreeSpot() const {
    return freeSpot;
}
