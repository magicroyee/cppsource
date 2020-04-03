#include <iostream>
using namespace std;

class Point 
{
private:
    double x_m;
    double y_m;
public:
    Point(double x = 0.0, double y = 0.0);
    double GetX() {return x_m;}
    double GetY() {return y_m;}
};

Point::Point(double x, double y)
{
    x_m = x;
    y_m = y;
}

class Circle : public Point
{
private:
    double r_m;
public:
    Circle(double x = 0, double y = 0, double r = 0);
    double GetR() {return r_m;}
    double Area() {return (3.14*r_m*r_m);}
};

Circle::Circle(double x, double y, double r) : Point(x, y), r_m(r)
{
}

int main(void)
{
    double x, y, r;
    cin >> x >> y >> r;
    Circle c1(x, y, r);
    cout << "圆心位于(" << c1.GetX() << "," << c1.GetY() << ")半径为"
        << c1.GetR() << "的圆形面积是" << c1.Area() << endl;

    return 0;
}