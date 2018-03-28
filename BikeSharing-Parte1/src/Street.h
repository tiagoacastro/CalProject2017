#ifndef STREET_H_
#define STREET_H_

#include <string>
#include "Node.h"
using namespace std;

class Street
{

private:
    unsigned long long int id;
    string name;
    bool twoWays;
    double slope;
	Node* node1;
	Node* node2;

public:
	Street() {};
	Street(unsigned long long int id, string name, bool twoWays);
    unsigned long long int getId() const;
    void setId(unsigned long long int id);
    const string &getName() const;
    void setName(const string &name);
    bool isTwoWays() const;
    void setTwoWays(bool twoWays);
    double getSlope() const;
    void setSlope(double slope);
};


#endif /* STREET_H_ */
