class Person {
public:
    const string& getName()const { return name;}
    const string& getAddress() const { return address;}
    istream &read(istream &is, Person &person);
private:
    string name;
    string address;
};

istream &Person::read(istream &is, Person &person) {
    is >> person.name >> person.address;
    return is;
}

ostream &print(ostream &os, Person &person) {
    os << person.getName() << " " << person.getAddress() << endl;
    return os;
}
