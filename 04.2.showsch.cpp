#include <iostream>
#include <string>
using namespace std;

class person 
{
private:
    string name;
    int num;
public:
    person(const string & s = "none", int n = 0);
    string showname() {return name;}
    int shownum() {return num;}
};

person::person(const string & s, int n) : name(s), num(n)
{
}

class student : public person
{
private:
    string cla;
    double score;
public:
    student(const string & c = "none", double s = 0, const string & na = "none", int n = 0);
    string showcla() {return cla;}
    double showscore() {return score;}
};

student::student(const string & c, double s, const string & na, int n) : person(na, n), cla(c), score(s)
{
}

class teacher : public person
{
private:
    string jobtitle;
    int papers;
public:
    teacher(const string & jt = "none", int p = 0, const string & na = "none", int n = 0);
    string showjt() {return jobtitle;}
    int showpapers() {return papers;}
};

teacher::teacher(const string & jt, int p, const string & na, int n) : person(na, n), jobtitle(jt), papers(p)
{
}

int main(void)
{
    string name, cla, jt;
    int num, papers;
    double score;
    cin >> name >> num >> cla >> score;
    student s1(cla, score, name, num);
    cin >> name >> num >> jt >> papers;
    teacher t1(jt, papers, name, num);

    cout << "Studentinformation:" << endl
        << "Name:" << s1.showname() << endl
        << "Number:" << s1.shownum() << endl
        << "Course:" << s1.showcla() << endl
        << "Grade:" << s1.showscore() << endl
        << endl;
    cout << "Teacherinformation:" << endl
        << "Name:" << t1.showname() << endl
        << "Number:" << t1.shownum() << endl
        << "pro:" << t1.showjt() << endl
        << "paper:" << t1.showpapers() << endl;

    return 0;
}