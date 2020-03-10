#include <iostream>
#include <cmath>
using namespace std;

class CPoint 
{
private:
    double x_m;
    double y_m;
public:
    CPoint(double x, double y);
    void setxy(double x, double y);
    friend double dist(const CPoint & p1, const CPoint & p2);
};

CPoint::CPoint(double x, double y)
{
    x_m = x;
    y_m = y;
}

void CPoint::setxy(double x, double y)
{
    x_m = x;
    y_m = y;
}

double dist(const CPoint & p1, const CPoint & p2)
{
    double dis;
    dis = sqrt(pow(p1.x_m - p2.x_m, 2.0) + pow(p1.y_m - p2.y_m, 2.0));

    return dis;
}

int main()
{
    double xt, yt, dis;

    cin >> xt >> yt;
    CPoint p1(xt, yt);
    cin >> xt >> yt;
    CPoint p2(xt, yt);

    dis = dist(p1, p2);

    cout << "Distance=" << dis << endl;

    return 0;
}