#include <iostream>
using namespace std;

template<class type>
class listNode
{
public:
	type data;
	listNode<type> * next;
	listNode() {next = NULL;}
	listNode(const type &item, listNode<type> * next1 = NULL) {data = item; next = next1;}
};

template<class type>
class list
{
protected:
	listNode<type> * head;
	int length;
public:
	list() {head = new listNode<type>; length = 0;}
	~list();
	listNode<type> * findNo(int n);
	int findValue(type value);
	bool add(const type& item);
	bool insert(const type &item, int n);
	bool remove(int n);
	void show();
};

template<class type>
list<type>::~list()
{
	listNode<type> * temp;
	while(head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

template<class type>
listNode<type> * list<type>::findNo(int n)
{
	listNode<type> * temp = head;
	for (int i = 0; i < n; i++)
	{
		temp = temp->next;
	}
	return temp;
}

template<class type>
int list<type>::findValue(type value)
{
	int n = 0;
	listNode<type> * temp = head;
	for (int i = 0; i < length; i++)
	{
		temp = temp->next;
		n++;
		if (value == temp->data)
			return n;
	}
	return 0;
}

template<class type>
bool list<type>::add(const type &item)
{
	listNode<type> * p = head;
	for (int i = 0; i < length; i++)
		p = p->next;
	p->next = new listNode<type>(item);
	length++;
	return true;
}

template<class type>
bool list<type>::insert(const type &item, int n)
{
	listNode<type> * p = head;
	listNode<type> * temp;
	if (n <= length)
	{
		for (int i = 0; i < n; i++)
			p = p->next;
		temp = p->next;
		p->next = new listNode<type>(item, temp);
		length++;
		return true;
	}
	return false;
}

template<class type>
bool list<type>::remove(int n)
{
	listNode<type> * p = head;
	listNode<type> * temp;
	if (n <= length && n > 0)
	{
		for (int i = 0; i < n-1; i++)
			p = p->next;
		temp = p->next;
		p->next = p->next->next;
		delete temp;
		return true;
	}
	return false;
}

template<class type>
void list<type>::show()
{
	listNode<type> * p = head;
	while (p->next != NULL)
	{
		p=p->next;
		cout << p->data;
		cout << (p->next==NULL? '\n' : ' ');
	}
}

int main(void)
{
	list<int> del;
	int num, no;
	char c;

	do {
		cin >> num;
		del.add(num);
		cin.get(c);
	} while(c != '\n');

	cin >> num;
	no = del.findValue(num);
	del.remove(no-1);
	del.show();

	return 0;
}