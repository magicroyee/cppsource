#include <iostream>
#include <string>
using namespace std;

class book
{
private:
    int bookid;
    string bookname;
    string pubhouse;
    double price;
public:
    book(int bid, string & bn, string & ph, double pc) : bookid(bid), bookname(bn), pubhouse(ph), price(pc) {}
    void show();
};

void book::show()
{
    cout << "Num:" << bookid << endl
        << "BookName:" << bookname << endl
        << "BookConcern:" << pubhouse << endl
        << "Price:" << price << endl;
}

class author
{
private:
    string name;
    int age;
    int time[3];
public:
    author(string & n, int a, int y, int m, int d);
    void show();
};

author::author(string & n, int a, int y, int m, int d) : name(n), age(a)
{
    time[0] = y;
    time[1] = m;
    time[2] = d;
}

void author::show()
{
    cout << "AuthorName:" << name << endl
        << "AuthorAge:" << age << endl
        << "PrintTime:" << time[0] << "-" << time[1] << "-" << time[2] << endl;
}

class card : public book, public author
{
private:
    string sys;
public:
    card(int bid, string & bn, string & ph, double pc, string & n, int a, int y, int m, int d, string & sy);
    void show();
};

card::card(int bid, string & bn, string & ph, double pc, string & n, int a, int y, int m, int d, string & sy)
    : book(bid, bn, ph, pc), author(n, a, y, m, d), sys(sy) {}

void card::show()
{
    cout << "SysName:" << sys << endl;
    book::show();
    author::show();
}

int main(void)
{
    string sys, bn, ph, an;
    int id, age, y, m, d;
    double pc;

    cin >> sys >> id >> bn >> ph >> pc
        >> an >> age >> y >> m >> d;
    card ca(id, bn, ph, pc, an, age, y, m, d, sys);

    ca.show();

    return 0;
}
