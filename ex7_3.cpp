#include <iostream>
#include <string>

using namespace std;

struct Sales_data {
    string isbn() const { return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream&, const Sales_data&);
istream &read(istream&, Sales_data&);

double Sales_data::avg_price()const {
    if(units_sold)
        return revenue / units_sold;
    else
        return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

ostream& print(ostream& os, const Sales_data& rhs) {
    os << rhs.bookNo << ":" << rhs.units_sold << " " << rhs.revenue << endl;
    return os;
}

istream &read(istream& is, Sales_data& rhs) {
    is >> rhs.bookNo >> rhs.units_sold >> rhs.revenue;
    return is;
}



int main(int argc, char *argv[])
{
    Sales_data total;
    if(read(cin, total)) {
        Sales_data trans;
        while(read(cin, trans)) {
            if(total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    } else {
        cerr << "No data?!" << endl;
    }
    
    return 0;
}
