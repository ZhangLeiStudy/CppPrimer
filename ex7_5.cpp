#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    const string& getName()const { return name;}
    const string& getAddress() const { return address;}

private:
    string name;
    string address;
};
