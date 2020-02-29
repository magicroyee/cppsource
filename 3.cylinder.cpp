#include <iostream>
using namespace std;

const double pi = 3.14;

class cylinder
{
private:
    double radius;
    double height;
    double volume;

public:
    void cylmaker()
    {
        cin >> radius >> height;
    }
    void ovolume()
    {
        volume = pi * radius * radius * height;
        cout << "v=" << volume << endl;
    }
};

int main(void)
{
    cylinder cyl;

    cyl.cylmaker();
    cyl.ovolume();

    return 0;
}