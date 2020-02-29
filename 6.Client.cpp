#include <iostream>
#include <string>
using namespace std;

class Client
{
private:
    char * m_name;
    int m_age;
public:
    Client(string name, int age);
    ~Client();
    void display();
};

Client::Client(string name, int age)
{
    int length = name.length();
    m_name = new char [length];
    for (int i = 0; i < length; i++)
    {
        m_name[i] = name[i];
    }
    m_age = age;
}

Client::~Client()
{
    delete [] m_name;
}

void Client::display()
{
    cout << "Name:" << m_name << endl
        << "Age:" << m_age << endl;
}

int main(void)
{
    string name;
    int age;
    cin >> name >> age;

    Client xm(name, age);
    xm.display();

    return 0;
}
