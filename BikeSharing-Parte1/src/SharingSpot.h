#ifndef SHARINGSPOT_H_
#define SHARINGSPOT_H_

#include "Node.h"

class SharingSpot: public Node{

private:
	bool freeSpot;

public:
	SharingSpot();
	~SharingSpot();
    bool isFreeSpot() const;
    void setFreeSpot(bool freeSpot);
};

#endif /* SHARINGSPOT_H_ */
