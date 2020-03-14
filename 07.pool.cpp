#include <iostream>
using namespace std;

const double PI = 3.14159;

class Circle
{
private:
    double radius;

public:
    Circle(double r);
    double perimeter();
    double area();
};

Circle::Circle(double r)
{
    radius = r;
}

double Circle::perimeter()
{
    return 2 * PI * radius;
}

double Circle::area()
{
    return PI * radius*radius;
}

int main(void)
{
    double r;
    cin >> r;

    Circle pool(r);
    Circle aisle(r+3);

    cout << "Enter the radius of the pool:" << r << endl;
    cout << "Fencing Cost is " << 35 * aisle.perimeter() << endl
        << "Concrete Cost is " << 20 * (aisle.area() - pool.area()) << endl;

    return 0;
}
