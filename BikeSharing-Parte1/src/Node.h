#ifndef NODE_H_
#define NODE_H_


class Node {

protected:
    unsigned long id;
    double longitude;
    double latitude;

public:
    /**
    * Node default constructor
    */
    Node() = default;
    /**
	 * Node constructor
	 * @param id 		    node id
	 * @param latitude  	node latitude
	 * @param longitude 	node longitude
	 */
    Node(unsigned long long int id, double latitude, double longitude);
    /**
	 * Getter which returns the node id
	 * @return id
	 */
    unsigned int getId() const;
    /**
	 * Getter which returns the node Longitude
	 * @return longitude
	 */
    double getLongitude() const;
    /**
	 * Getter which returns the node Latitude
	 * @return latitude
	 */
    double getLatitude() const;
};

#endif /* NODE_H_ */
