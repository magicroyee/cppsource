#include <iostream>
using namespace std;

class intSet
{
private:
    int length;
    int *set;

public:
    intSet();
    intSet(const int *s, int l = 1);
    intSet(const intSet & i1);
    ~intSet();
    void intSetShow() const;
    friend intSet operator+(const intSet &i1, const intSet &i2);
    friend intSet operator-(const intSet &i1, const intSet &i2);
};

intSet::intSet()
{
}

intSet::intSet(const int *s, int l)
{
    length = l;
    set = new int[l];
    for (int i = 0; i < l; i++)
    {
        set[i] = s[i];
    }
}

intSet::intSet(const intSet & i1)
{
    length = i1.length;
    set = new int[length];
    for (int i = 0; i < length; i++)
    {
        set[i] = i1.set[i];
    }
}

intSet::~intSet()
{
    delete[] set;
}

void intSet::intSetShow() const
{
    for (int i = 0; i < length; i++)
    {
        cout << set[i];
        if (i != length - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
}

intSet operator+(const intSet &i1, const intSet &i2)
{
    intSet re(i1.set, i1.length + i2.length);

    int flag = 0;
    for (int i = 0; i < i2.length; i++)
    {
        static int truelen = i1.length;
        flag = 0;
        for (int j = 0; j < i1.length; j++)
        {
            if (i2.set[i] == i1.set[j])
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            re.set[truelen++] = i2.set[i];
        }
        else
        {
            re.length -= 1;
        }
    }

    return re;
}

intSet operator-(const intSet &i1, const intSet &i2)
{
    intSet re(i1.set, i1.length);

    int flag = 0;
    for (int i = 0; i < i2.length; i++)
    {
        static int pos = 0;
        flag = 0;
        for (int j = 0; j < re.length; j++)
        {
            if (i2.set[i] == re.set[j])
            {
                flag = 1;
                pos = j;
                break;
            }
        }

        if (flag == 1)
        {
            re.length -= 1;
            for (int j = pos; j < re.length; j++)
            {
                re.set[j] = re.set[j + 1];
            }
        }
    }

    return re;
}



int main(void)
{
    int numtemp;
    int *settemp;

    cin >> numtemp;
    settemp = new int [numtemp];
    for (int i = 0; i < numtemp; i++)
    {
        cin >> settemp[i];
    }
    intSet int1(settemp, numtemp);
    delete [] settemp;
    
    cin >> numtemp;
    settemp = new int [numtemp];
    for (int i = 0; i < numtemp; i++)
    {
        cin >> settemp[i];
    }
    intSet int2(settemp, numtemp);
    delete [] settemp;

    intSet add(int1 + int2);
    cout << "int1+int2=";
    add.intSetShow();

    intSet dif(int1 - int2);
    cout << "int1-int2=";
    dif.intSetShow();

    return 0;
}