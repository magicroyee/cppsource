#include <iostream>
using namespace std;

const char city[6][10] = {"天津","上海","太原","广州","昆明","新疆"};
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
    cout << "目的地：" << city[No-1] << endl;
    cout << "重量：" << zh << "KG" << endl;
    cout << "货物个数：" << Num << endl;
}

void Expresscom::Disp()
{
    Edisp();
    Feiyong();
    cout << "单价：" << fee << endl;
    cout << "总运费：" << feesum << endl;
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
    cout << "公司名称：E通宝" << endl;
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
    cout << "公司名称：顺风" << endl;
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
    cout << "公司名称：EMS" << endl;
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
    cout << "公司名称：圆通" << endl;
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