class Person {
    friend istream &read(istream &is, Person &person);
    friend ostream &print(ostream &os, const Person &person);
public:
    Person()=default;
    Person(const string &s, const string &add) : name(s), address(add)
    {
    }
    Person(istream &is) { read(is, *this); }
    const string& getName()const { return name;}
    const string& getAddress() const { return address;}
private:
    string name;
    string address;
};

//member function
istream &read(istream &is, Person &person) {
    is >> person.name >> person.address;
    return is;
}

//nonmember function
ostream &print(ostream &os, const Person &person) {
    os << person.getName() << " " << person.getAddress() << endl;
    return os;
}
