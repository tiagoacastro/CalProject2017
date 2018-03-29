#ifndef SHARINGSPOT_H_
#define SHARINGSPOT_H_

#include "Node.h"

class SharingSpot: public Node{

private:
	bool freeSpot;

public:
	/**
	 * Sharing spot constructor (wether it is free or not is calculated here)
	 * @param n		node where the sharing spot will be placed
	 */
	explicit SharingSpot(Node n);
	/**
    * Getter which returns wether the sharing spot is free or not
    * @return if the spot is free or not
    */
    bool isFreeSpot() const;
};

#endif /* SHARINGSPOT_H_ */
