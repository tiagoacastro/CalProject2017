#ifndef USER_H_
#define USER_H_

#include <string>
using namespace std;

class User {

private:
    unsigned int id;
    string payingMethod;

public:
    User();
    ~User();
    unsigned int getId() const;
    void setId(unsigned int id);
    const string &getPayingMethod() const;
    void setPayingMethod(const string &payingMethod);
};


#endif /*USER_H_*/
