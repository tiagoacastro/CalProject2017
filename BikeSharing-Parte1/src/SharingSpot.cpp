
#include "SharingSpot.h"

bool SharingSpot::isFreeSpot() const {
    return freeSpot;
}

void SharingSpot::setFreeSpot(bool freeSpot) {
    SharingSpot::freeSpot = freeSpot;
}
