struct Sales_data;

istream &read(istream& is, Sales_data& rhs);

struct Sales_data {
    Sales_data()=default;
    Sales_data(const string &s):bookNo(s) { }
    Sales_data(const string &s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(n * p) { }
    Sales_data(istream &is) {
        read(is, *this);
    }
    
    
    string isbn() const { return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

//member function
double Sales_data::avg_price()const {
    if(units_sold)
        return revenue / units_sold;
    else
        return 0;
}

//member function
Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}


//nonmember function
ostream& print(ostream& os, const Sales_data& rhs) {
    os << rhs.isbn() << " " << rhs.units_sold << " " << rhs.revenue << " " << rhs.avg_price();
    return os;
}

istream &read(istream& is, Sales_data& rhs) {
    double price = 0;
    is >> rhs.bookNo >> rhs.units_sold >> price;
    rhs.revenue = price * rhs.units_sold;
    return is;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}


int main(int argc, char *argv[])
{
    //Sales_data total("zhang", 5, 2);
    Sales_data total(cin);
    print(cout, total);
    

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
