#include <iostream>
using namespace std;

int main(void)
{
    class time
    {
    private:
        int hour;
        int minute;
        int second;

    public:
        int seth(int h)
        {
            hour = h;
            return 0;
        }
        int setm(int m)
        {
            minute = m;
            return 0;
        }
        int sets(int s)
        {
            second = s;
            return 0;
        }
        int otime(void)
        {
            cout << hour << ":" << minute << ":" << second << endl;
            return 0;
        }
    };

    int h, m, s;
    cin >> h >> m >> s;

    time time1;
    time1.seth(h);
    time1.setm(m);
    time1.sets(s);

    time1.otime();

    return 0;
}