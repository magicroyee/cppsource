#include <iostream>
#include <string>
using namespace std;

class employee
{
private:
    string name;
protected:
    int money;
public:
    employee(const char * n) : name(n) {};
    virtual ~employee() {};
    virtual void monres() {};
    virtual void monres(int x) {};
    void show() {cout << name << "本月工资" << money << endl;};
};

class manager : public employee
{
public:
    manager(const char * n) : employee(n) {};
    ~manager() {};
    void monres() {money = 8000;};
    void monres(int x) {money = 8000;};
};

class technician : public employee
{
public:
    technician(const char * n) : employee(n) {};
    ~technician() {};
    void monres() {};
    void monres(int x) {money = 100 * x;};
};

class sales : public employee
{
public:
    sales(const char * n) : employee(n) {};
    ~sales() {};
    void monres() {};
    void monres(int x) {money = x * 4 / 100;};
};

class salesmanager : public employee
{
public:
    salesmanager(const char * n) : employee(n) {};
    ~salesmanager() {};
    void monres() {};
    void monres(int x) {money = 5000 + x * 5/1000;};
};

int main(void)
{
    manager t("Tom");
    technician j("John");
    salesmanager a("Antony");
    sales ja("Jane");

    t.monres();
    t.show();

    int temp;
    cin >> temp;
    j.monres(temp);
    j.show();

    cin >> temp;
    a.monres(temp);
    a.show();

    cin >> temp;
    ja.monres(temp);
    ja.show();

    return 0;
}