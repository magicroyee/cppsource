#include <iostream>
#include <string>
using namespace std;

class counter 
{
private:
    int num;
    string str;
public:
    counter(string s);
    void countWord();
    void show();
};

counter::counter(string s)
{
    num = 0;
    str = s;
}

void counter::countWord()
{
    int flag = 0;
    int length = str.length();
    for (int i = 0; i < length; i++)
    {
        if (str[i] == ' ')
        {
            flag = 0;
        }
        else if (flag == 0)
        {
            flag = 1;
            num++;
        }
    }
}

void counter::show()
{
    cout << "Words=" << num << endl;
}

int main(void)
{
    string s;
    getline(cin, s);

    counter word(s);
    word.countWord();
    word.show();

    return 0;
}
