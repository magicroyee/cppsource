#include <iostream>
using namespace std;

const char city[6][10] = {"���","�Ϻ�","̫ԭ","����","����","�½�"};
double allfee[4][6][3] = {
    {10, 14, 18, 15, 19, 23, 15, 19, 23, 15, 21, 27, 15, 21, 27, 15, 25, 35},
    {12, 14, 16, 20, 30, 40, 20, 28, 36, 20, 34, 46, 20, 32, 44, 20, 34, 48},
    {26, 38, 50, 26, 38, 50, 26, 38, 50, 29, 47, 65, 35, 65, 95, 38, 66, 95},
    {10, 18, 26, 10, 18, 26, 12, 24, 36, 12, 22, 32, 15, 27, 39, 18, 33, 48}
};

class Expresscom
{
protected:
    int No, Num;
    double zh;
    int fee, feesum;
    double (*feelist)[3];
public:
    Expresscom(int no, int num, double zhong) : No(no), Num(num), zh(zhong) {};
    virtual ~Expresscom() {};
    double Feiyong();
    virtual void Disp();
    void Edisp();
};

double Expresscom::Feiyong()
{
    int z;
    z = (int)zh;

    fee = feelist[No-1][z-1];
    feesum = fee * Num;

    return feesum;
}

void Expresscom::Edisp()
{
    cout << "Ŀ�ĵأ�" << city[No-1] << endl;
    cout << "������" << zh << "KG" << endl;
    cout << "���������" << Num << endl;
}

void Expresscom::Disp()
{
    Edisp();
    Feiyong();
    cout << "���ۣ�" << fee << endl;
    cout << "���˷ѣ�" << feesum << endl;
}

class Etong : public Expresscom
{
public:
    Etong(int no, int num, double zhong) : Expresscom(no, num, zhong) {feelist = allfee[0];};
    ~Etong() {};
    void Disp();
};

void Etong::Disp()
{
    cout << "��˾���ƣ�Eͨ��" << endl;
    Expresscom::Disp();
}

class shunfeng : public Expresscom
{
public:
    shunfeng(int no, int num, double zhong) : Expresscom(no, num, zhong) {feelist = allfee[1];};
    ~shunfeng() {};
    void Disp();
};

void shunfeng::Disp()
{
    cout << "��˾���ƣ�˳��" << endl;
    Expresscom::Disp();
}

class EMS : public Expresscom
{
public:
    EMS(int no, int num, double zhong) : Expresscom(no, num, zhong) {feelist = allfee[2];};
    ~EMS() {};
    void Disp();
};

void EMS::Disp()
{
    cout << "��˾���ƣ�EMS" << endl;
    Expresscom::Disp();
}

class yuantong : public Expresscom
{
public:
    yuantong(int no, int num, double zhong) : Expresscom(no, num, zhong) {feelist = allfee[3];};
    ~yuantong() {};
    void Disp();
};

void yuantong::Disp()
{
    cout << "��˾���ƣ�Բͨ" << endl;
    Expresscom::Disp();
}

int main(void)
{
    int com, ci, num;
    double zh;
    cin >> com >> ci >> num >> zh;

    Expresscom * p;
    switch(com)
    {
    case 1: p = new Etong(ci, num, zh); break;
    case 2: p = new shunfeng(ci, num, zh); break;
    case 3: p = new EMS(ci ,num, zh); break;
    case 4: p = new yuantong(ci, num, zh); break;
    default: p = new Expresscom(ci, num, zh);
    }

    p->Disp();

    delete p;
    return 0;
}