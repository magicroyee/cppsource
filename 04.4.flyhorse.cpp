#include <iostream>
using namespace std;

class animal
{
private:
    int m_weight;
public:
    animal(int w) : m_weight(w) {}
    int GetWeight() {return m_weight;}
};

class horse : virtual public animal
{
public:
    horse(int w) : animal(w) {}
    void run() {cout << "I can run." << endl;}
};

class bird : virtual public animal
{
public:
    bird(int w) : animal(w) {}
    void fly() {cout << "I can fly." << endl;}
};

class pegasus : public horse, public bird
{
public:
    pegasus(int w) : animal(w), horse(w), bird(w) {}
    void show();
};

void pegasus::show()
{
    cout << "I am a Pegasus." << endl;
    cout << "My weight is " << GetWeight() << "kg." << endl;
    run();
    fly();
}

int main(void)
{
    int weight;
    cin >> weight;
    pegasus peg(weight);

    peg.show();

    return 0;
}