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
    ~Date();
    int GetDay();
    int GetMonth();
    int GetYear();
    void ShowDate();
};

Date::Date(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}

Date::~Date()
{
    
}

int Date::GetDay()
{
    return day;
}

int Date::GetMonth()
{
    return month;
}

int Date::GetYear()
{
    return year;
}

void Date::ShowDate()
{
    cout << year << "/" << month << "/" << day << endl;
}

int main(void)
{
    int y, m, d;
    cin >> y >> m >> d;

    Date aday(y, m, d);
    aday.ShowDate();

    cout << "year " << aday.GetYear() << endl;
    cout << "month " << aday.GetMonth() << endl;
    cout << "day " << aday.GetDay() << endl;

    return 0;
}