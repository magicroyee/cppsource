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
	list<type>& setFromLine();
	listNode<type> * findNo(int n);
	int getLength() {return length;}
	int findValue(type value);
	bool isNull();
	bool add(const type& item);
	bool insert(const type &item, int n);
	bool remove(int n);
	void clear();
	void show();
};

template<class type>
list<type>::~list()
{
	while(head->next != NULL)
		remove(1);
	delete head;
}

template<class type>
list<type>& list<type>::setFromLine()
{
	int num;
	char c;

	do {
		cin >> num;
		add(num);
		cin.get(c);
	} while(c != '\n');
	return *this;
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
bool list<type>::isNull()
{
	if (head->next == NULL)
		return true;
	else
		return false;
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
void list<type>::clear()
{
	while(head->next != NULL)
		remove(1);
}

template<class type>
void list<type>::show()
{
	listNode<type> * p = head;
	while (p->next != NULL)
	{
		p=p->next;
		cout << p->data;
		cout << ' ';
	}
	cout << '\n';
}

int main(void)
{
	list<int> A, B, both;
	int tempa, tempb;

	A.setFromLine();
	B.setFromLine();

	for (int i = 1; i <= A.getLength(); i++)
	{
		tempa = A.findNo(i)->data;
		for (int j = 1; j <= B.getLength(); j++)
		{
			tempb = B.findNo(j)->data;
			if(tempa == tempb)
			{
				both.add(tempa);
			}
			else
				continue;
		}
	}

	if (both.isNull())
		cout << "没有交集" << endl;
	else
		both.show();

	return 0;
}