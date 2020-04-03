#include <iostream>
using namespace std;

class Date 
{
private:
    int year;
    int month;
    int day;
public:
    Date(int y, int m, int d);
    friend ostream & operator<<(ostream & os, const Date & d);
};

Date::Date(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}

ostream & operator<<(ostream & os, const Date & d)
{
    os << d.year << "-" << d.month << "-" << d.day << endl;
    return os;
}

int main()
{
    int y, m, d;
    cin >> y >> m >> d;

    Date dat(y, m, d);
    cout << dat;

    return 0;
}