#include "SharingSpot.h"

SharingSpot::SharingSpot(Node n){
    Node(n.getId(),n.getLatitude(),n.getLongitude());
}

bool SharingSpot::isFreeSpot() const {
    return freeSpot;
}
