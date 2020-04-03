#include <iostream>
#include <string>
using namespace std;

class str 
{
    int len;
    char * s_m;
public:
    str();
    str(const char * s, int l = 1);
    ~str();
    int getline(int l = 255);
    friend bool operator==(const str & str1, const str & str2);
};

str::str()
{
    s_m = new char;
}

str::str(const char * s, int l)
{
    len = l;
    s_m = new char [l];
    for (int i = 0; i < l; i++)
        s_m[i] = s[i];
}

str::~str()
{
    delete [] s_m;
}

int str::getline(int l)
{
    delete [] s_m;
    len = 0;
    s_m = new char [l];
    char temp;
    while ((temp = cin.get()) != '\n')
    {
        s_m[len++] = temp;
    }

    return len;
}

bool operator==(const str & str1, const str & str2)
{
    if (str1.len == str2.len)
    {
        for (int i = 0; i < str1.len; i++)
        {
            if (str1.s_m[i] == str2.s_m[i])
                continue;
            else
                return false;
        }
        
        return true;
    }
    else
        return false;
}

int main()
{
    str str1, str2;

    str1.getline();
    str2.getline();

    if (str1 == str2)
        cout << "str1=str2" << endl;
    else
        cout << "str1!=str2" << endl;

    return 0;
}