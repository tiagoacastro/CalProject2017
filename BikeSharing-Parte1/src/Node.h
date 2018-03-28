#ifndef NODE_H_
#define NODE_H_


class Node {

protected:
    unsigned long id;
    double longitude;
    double latitude;

public:
    Node(unsigned long long int id, double latitude, double longitude);
    Node(){};
    unsigned int getId() const;
    void setId(unsigned long id);
    double getLongitude() const;
    void setLongitude(double longitude);
    double getLatitude() const;
    void setLatitude(double latitude);
};

#endif /* NODE_H_ */
