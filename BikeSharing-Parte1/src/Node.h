#ifndef NODE_H_
#define NODE_H_


class Node {

protected:
    unsigned int id;
    double longitude;
    double latitude;

public:
    Node();
    ~Node();
    unsigned int getId() const;
    void setId(unsigned int id);
    double getLongitude() const;
    void setLongitude(double longitude);
    double getLatitude() const;
    void setLatitude(double latitude);
};

#endif /* NODE_H_ */
