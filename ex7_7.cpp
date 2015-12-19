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
    os << rhs.isbn() << " " << rhs.units_sold << " " << rhs.revenue << rhs.avg_price();
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
