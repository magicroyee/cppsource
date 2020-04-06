#include <iostream>
using namespace std;

class Felid
{
public:
    Felid() {cout << "Felid constructor\n";};
    virtual ~Felid() {cout << "Felid destructor\n";};
    virtual void sound() {};
};

class Cat : public Felid
{
public:
    Cat() {cout << "Cat constructor\n";};
    ~Cat() {cout << "Cat destructor\n";};
    void sound() {cout << "Miaow !\n";};
};

class Leopard : public Felid
{
public:
    Leopard() {cout << "Leopard constructor\n";};
    ~Leopard() {cout << "Leopard destructor\n";};
    void sound() {cout << "Howl !\n";};
};

int main(void)
{
    Felid * f;
    f = new Cat;
    f->sound();
    delete f;

    f = new Leopard;
    f->sound();
    delete f;

    return 0;
}