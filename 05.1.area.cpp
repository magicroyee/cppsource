#include <iostream>
using namespace std;

class shape
{
private:
    double x;
    double y;
public:
    shape(double xi, double yi) {x = xi; y = yi;}
    double getx() {return x;}
    double gety() {return y;}
    virtual double area() {return 0;}
    virtual void show() {}
};

class triangle : public shape
{
public:
    triangle(double xi, double yi) : shape(xi, yi) {}
    double area() {return getx() * gety() / 2;}
    void show() {cout << "triangleArea=" << area() << endl;}
};

class rectangle : public shape
{
public:
    rectangle(double xi, double yi) : shape(xi, yi) {}
    double area() {return getx() * gety();}
    void show() {cout << "rectangleArea=" << area() << endl;}
};

class circle : public shape
{
public:
    circle(double xi, double yi) : shape(xi, yi) {}
    double area() {return 3.14 * getx() * getx();}
    void show() {cout << "circleArea=" << area() << endl;}
};

int main(void)
{
    double xi, yi;
    cin >> xi >> yi;

    triangle tri(xi, yi);
    tri.show();

    rectangle rec(xi, yi);
    rec.show();

    circle cir(xi, yi);
    cir.show();

    return 0;
}