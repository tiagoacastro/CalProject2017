#ifndef STREET_H_
#define STREET_H_

#include <string>
using namespace std;

class Street
{

private:
    unsigned int id;
    string name;
    bool twoWays;
    double slope;

public:
	Street();
	~Street();
    unsigned int getId() const;
    void setId(unsigned int id);
    const string &getName() const;
    void setName(const string &name);
    bool isTwoWays() const;
    void setTwoWays(bool twoWays);
    double getSlope() const;
    void setSlope(double slope);
};


#endif /* STREET_H_ */
