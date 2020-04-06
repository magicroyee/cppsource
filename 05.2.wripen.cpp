#include <iostream>
using namespace std;

class wripen
{
public:
    wripen() {};
    virtual ~wripen() {};
    virtual void writing() {};
};

class pencil : public wripen
{
public:
    pencil() {};
    ~pencil() {};
    void writing() {cout << "I'm a pencil.\n";};
};

class pen : public wripen
{
public:
    pen() {};
    ~pen() {};
    void writing() {cout << "I'm a pen.\n";};
};

int main(void)
{
    char temp;
    wripen * wp;
    pencil c;
    pen p;
    cin >> temp;

    if (temp == 'c')
        wp = &c;
    else
        wp = &p;
    
    wp->writing();

    return 0;
}