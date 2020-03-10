#include <iostream>
using namespace std;

class student
{
private:
    int num_m;
    int score;
public:
    student(int n = 1, int s = 1);
    student operator=(const student & s);
    friend istream & operator>>(istream & is, student & s);
    friend ostream & operator<<(ostream & os, const student & s);
    friend void quikSort(student * group, int s, int e);
};

student::student(int n, int s)
{
    num_m = n;
    score = s;
}

student student::operator=(const student & s)
{
    num_m = s.num_m;
    score = s.score;
    return s;
}

istream & operator>>(istream & is, student & s)
{
    is >> s.num_m >> s.score;
    return is;
}
ostream & operator<<(ostream & os, const student & s)
{
    os << "Ñ§ºÅ:" << s.num_m << "  ³É¼¨:" << s.score << endl;
    return os;
}

void quikSort(student * group, int s, int l)
{
    int i = s, j = l - 1;
    student temp(group[i]);
    while (i != j)
    {
        while((group[j]).score <= temp.score && i < j)
            j--;
        if (i < j)
            group[i] = group[j];
        while((group[i]).score >= temp.score && i < j)
            i++;
        if (i < j)
            group[j] = group[i];
    }
    group[i] = temp;
    if (s < i - 1)
        quikSort(group, s, i);
    if (i < l - 1)
        quikSort(group, i + 1, l);
}

int main(void)
{
    int num;
    student * group;

    cin >> num;
    group = new student [num];
    
    for (int i = 0; i < num; i++)
    {
        cin >> group[i];
    }

    quikSort(group, 0, num);

    for (int i = 0; i < num; i++)
    {
        cout << group[i];
    }

    return 0;
}