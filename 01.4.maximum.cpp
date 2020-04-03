#include <iostream>
using namespace std;

int main(void)
{
    int num1, num2, num3, max;
    cin >>num1 >>num2 >>num3;

    max = num1 > num2? (num1 > num3? num1 : num3) : (num2 > num3? num2 : num3);

    cout << "Maximum:" << max << endl;

    return 0;
}