#include <iostream>
#include <cstring>
using namespace std;

class BaseString
{
private:
    char * Chstr;
    int Length;
public:
    BaseString(char * s);
    virtual ~BaseString() {delete [] Chstr;}
    void show() {cout << Chstr << endl;}
    const char * getstr() {return Chstr;}
    int getlen() {return Length;}
};

BaseString::BaseString(char * s)
{
    Length = strlen(s);
    Chstr = new char [Length + 1];
    strcpy(Chstr, s);
    Chstr[Length] = '\0';
}

class ReString : public BaseString
{
private:
    char * restr;
public:
    ReString(char * s);
    ~ReString() {delete [] restr;}
    void show() {cout << restr << endl;}
};

ReString::ReString(char * s) : BaseString(s)
{
    int l = strlen(s);
    restr = new char [l + 1];
    for (int i = 0; i < l; i++)
    {
        restr[i] = s[l-1-i];
    }
    restr[l] = '\0';
}

class CopyString : public BaseString
{
public:
    CopyString(char * s) : BaseString(s) {}
};

class CmpString : private BaseString
{
public:
    CmpString(char * s) : BaseString(s) {}
    bool cmp(const char * s, int l);
};

bool CmpString::cmp(const char * s, int l)
{
    if (l == BaseString::getlen())
    {
        for (int i = 0; i < l; i++)
        {
            if (s[i] != BaseString::getstr()[i])
                return false;
            else
                continue;
        }
        return true;
    }
    else
    {
        return false;
    }
}

int main(void)
{
    char temp[50];
    cin.getline(temp, 50);

    ReString re(temp);
    cout << "倒序输出：";
    re.show();

    cin.getline(temp, 50);
    CopyString co(temp);
    cout << "复制输出：";
    co.show();

    cin.getline(temp, 50);
    CmpString cm(temp);
    cin.getline(temp, 50);
    int l = strlen(temp);
    cout << "判断结果：两字符串";
    if (cm.cmp(temp, l) == true)
        cout << "相等。" << endl;
    else
        cout << "不相等。" << endl;
    
    return 0;
}