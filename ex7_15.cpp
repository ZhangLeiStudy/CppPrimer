class Person {
public:
    Person()=default;
    Person(const string &s, const string &add) : name(s), address(add)
    {
    }
    Person(istream &is) { read(is, *this); }
    const string& getName()const { return name;}
    const string& getAddress() const { return address;}
    istream &read(istream &is, Person &person);
private:
    string name;
    string address;
};

//member function
istream &Person::read(istream &is, Person &person) {
    is >> person.name >> person.address;
    return is;
}

//nonmember function
ostream &print(ostream &os, const Person &person) {
    os << person.getName() << " " << person.getAddress() << endl;
    return os;
}
