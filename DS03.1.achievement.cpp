#include <iostream>
using namespace std;

template <class type>
class listNode
{
public:
	type data;
	listNode<type> *next;
	listNode() { next = NULL; }
	listNode(const type &item, listNode<type> *next1 = NULL)
	{
		data = item;
		next = next1;
	}
};

template <class type>
class list
{
protected:
	listNode<type> *head;
	int length;

public:
	list()
	{
		head = new listNode<type>;
		length = 0;
	}
	virtual ~list();
	list<type> &setFromLine();
	listNode<type> *findNo(int n);
	int getLength() { return length; }
	int findValue(type value);
	bool isNull();
	bool add(const type &item);
	bool insert(const type &item, int n);
	bool remove(type &item, int n);
	void clear();
	void show();
};

template <class type>
list<type>::~list()
{
	type temp;
	while (head->next != NULL)
		remove(temp, 1);
	delete head;
}

template <class type>
list<type> &list<type>::setFromLine()
{
	int num;
	char c;

	do
	{
		cin >> num;
		add(num);
		cin.get(c);
	} while (c != '\n');
	return *this;
}

template <class type>
listNode<type> *list<type>::findNo(int n)
{
	listNode<type> *temp = head;
	for (int i = 0; i < n; i++)
	{
		temp = temp->next;
	}
	return temp;
}

template <class type>
int list<type>::findValue(type value)
{
	int n = 0;
	listNode<type> *temp = head;
	for (int i = 0; i < length; i++)
	{
		temp = temp->next;
		n++;
		if (value == temp->data)
			return n;
	}
	return 0;
}

template <class type>
bool list<type>::isNull()
{
	if (head->next == NULL)
		return true;
	else
		return false;
}

template <class type>
bool list<type>::add(const type &item)
{
	listNode<type> *p = head;
	for (int i = 0; i < length; i++)
		p = p->next;
	p->next = new listNode<type>(item);
	length++;
	return true;
}

template <class type>
bool list<type>::insert(const type &item, int n)
{
	listNode<type> *p = head;
	listNode<type> *temp;
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

template <class type>
bool list<type>::remove(type &item, int n)
{
	listNode<type> *p = head;
	listNode<type> *temp;
	if (n <= length && n > 0)
	{
		for (int i = 0; i < n - 1; i++)
			p = p->next;
		temp = p->next;
		p->next = p->next->next;
		item = p->data;
		delete temp;
		return true;
	}
	return false;
}

template <class type>
void list<type>::clear()
{
	while (head->next != NULL)
		remove(1);
}

template <class type>
void list<type>::show()
{
	listNode<type> *p = head;
	while (p->next != NULL)
	{
		p = p->next;
		cout << p->data;
		cout << ' ';
	}
	cout << '\n';
}

template <class type>
class stack : protected list<type>
{
public:
	stack() {}
	~stack() {}
	bool isEmpty() { return list<type>::length ? true : false; }
	bool push(type &item);
	bool pop(type &item);
	void show() { list<type>::show(); }
};

template <class type>
bool stack<type>::push(type &item)
{
	list<type>::add(item);
	return true;
}

template <class type>
bool stack<type>::pop(type &item)
{
	list<type>::remove(item, 0);
	return 0;
}

int main(void)
{
	int n;
	int temp;
	stack<int> unsixty, unhundred, uphundred;
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (temp < 60)
		{
			unsixty.push(temp);
		}
		else if (temp < 100)
		{
			unhundred.push(temp);
		}
		else
		{
			uphundred.push(temp);
		}
	}
	cout << "60>x:";
	unsixty.show();
	cout << "60<=x<100:";
	unhundred.show();
	cout << "x>=100:";
	uphundred.show();

	return 0;
}