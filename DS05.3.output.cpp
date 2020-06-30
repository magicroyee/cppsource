#include <iostream>
#include <string>
using namespace std;

template <class T>
class BinTreeNode
{
public:
	T data;					//������
	BinTreeNode<T> *Lchild; //����ָ��
	BinTreeNode<T> *Rchild; //�Һ���ָ��
							// ������ֵ��㣬����������
	BinTreeNode() : Lchild(NULL), Rchild(NULL) {}
	//������ֵ��㣬����������
	BinTreeNode(T &value) : data(value), Lchild(NULL), Rchild(NULL) {}
	//������ֵ�������������Ľ��
	BinTreeNode(T &value, BinTreeNode<T> *left, BinTreeNode<T> *right)
		: data(value), Lchild(left), Rchild(right) {}
	//�޸Ľ������ֵ
	void SetData(T &value) { data = value; }
	//ɾ����ǰ������������
	void release();
	//�޸Ľ������ָ��
	void SetLeft(BinTreeNode<T> *L);
	//�޸Ľ���Һ���ָ��
	void SetRight(BinTreeNode<T> *R);
	//�����Ե�ǰ���Ϊ���Ķ�����
	BinTreeNode<T> *copy();
};

template <class T>
BinTreeNode<T> *preSet(const string &s, int &p)
{
	if (s.size() == 0 || p == s.size() || s[p] == '#')
		return NULL;
	T t = s[p++];
	BinTreeNode<T> *temp = new BinTreeNode<T>(t);
	temp->Lchild = preSet<T>(s, p);
	temp->Rchild = preSet<T>(s, ++p);

	return temp;
}

template <class T>
void BinTreeNode<T>::release()
{
	if (Lchild != NULL)
	{
		Lchild->release(); //�ݹ�����ͷ�������
		delete Lchild;
		Lchild = NULL;
	}
	if (Rchild != NULL)
	{
		Rchild->release(); //�ݹ�����ͷ�������
		delete Rchild;
		Rchild = NULL;
	}
}

template <class T>
void BinTreeNode<T>::SetLeft(BinTreeNode<T> *L)
{
	Lchild->release(); //�ͷ�ԭ����������
	delete Lchild;	   //�ͷ��������ĸ����
	Lchild = L;		   //�޸���ָ��
}

template <class T>
void BinTreeNode<T>::SetRight(BinTreeNode<T> *R)
{
	Rchild->release(); //�ͷ�ԭ����������
	delete Rchild;	   //�ͷ��������ĸ����
	Rchild = R;		   //�޸�ָ��ָ��
}

template <class T>
BinTreeNode<T> *BinTreeNode<T>::copy()
{
	BinTreeNode<T> *newLeft, *newRight;
	if (Lchild != NULL)
		newLeft = Lchild->copy();
	else
		newLeft = NULL;
	if (Rchild != NULL)
		newRight = Rchild->copy();
	else
		newRight = NULL;
	BinTreeNode<T> *newptr = new BinTreeNode<T>(data, newLeft, newRight);
	return newptr;
}

template <class T>
class BinaryTree
{
protected:
	BinTreeNode<T> *root;

public:
	//���캯��
	BinaryTree() { root = NULL;};
	BinaryTree(BinTreeNode<T> *source) { root = source;};
	BinaryTree(const BinaryTree<T> &source)
	{
		root = source.root->copy();
	};
	BinaryTree(T value, BinTreeNode<T> *left, BinTreeNode<T> *right)
	{
		root = new BinTreeNode<T>(value, left, right);
	}
	//��������
	~BinaryTree()
	{
		root->release();
		delete root;
		root = NULL;
	}
	//�ж������շ���������Ϊ�գ�����1�����򷵻�0
	bool IsEmpty()
	{
		return root == NULL;
	}
	//ȡ��
	BinTreeNode<T> *GetRoot() { return root; }
	void PreOrder(BinTreeNode<T> *current);
	void InOrder(BinTreeNode<T> *current);
	void PostOrder(BinTreeNode<T> *current);
	int Size(const BinTreeNode<T> *t);
	int leafs(const BinTreeNode<T> *t);
	int Depth(const BinTreeNode<T> *t);
	BinTreeNode<T> *Find(BinTreeNode<T> *t, T &value);
	bool Insert(BinTreeNode<T> *&t, T &value);
};

//���������currentΪ�����������ݹ麯��
template <class T>
void BinaryTree<T>::PreOrder(BinTreeNode<T> *current)
{
	if (current != NULL)
	{
		cout << current->data << " ";	   //���ʸ����,���������ݴ�
		PreOrder(current->Lchild); //�������������
		PreOrder(current->Rchild); //�������������
	}
}

//���������currentΪ�����������ݹ麯��
template <class T>
void BinaryTree<T>::InOrder(BinTreeNode<T> *current)
{
	if (current != NULL) //current==NULLΪ�ݹ���ֹ����
	{
		InOrder(current->Lchild); //�������������
		cout << current->data << " ";	  //���ʸ���㣬���������ݴ�
		InOrder(current->Rchild); //�������������
	}
}

//���������currentΪ�����������ݹ麯��
template <class T>
void BinaryTree<T>::PostOrder(BinTreeNode<T> *current)
{
	if (current != NULL) //current==NULL�ǵݹ���ֹ����
	{
		PostOrder(current->Lchild); //�������������
		PostOrder(current->Rchild); //�������������
		cout << current->data << " ";		//���ʸ����, ���������
	}
}

template <class T>
int BinaryTree<T>::Size(const BinTreeNode<T> *t)
{ //������tΪ���Ķ������Ľ�����
	if (t == NULL)
		return 0;
	//�ݹ��������Ϊ������������Ϊ0
	else
		return 1 + Size(t->LChild) + Size(t->RChild);
}

template <class T>
int BinaryTree<T>::leafs(const BinTreeNode<T> *t)
{
	if (t == NULL)
		return 0;
	else if (t->Lchild == NULL && t->Rchild == NULL)
		return 1;
	else
		return leafs(t->Lchild) + leafs(t->Rchild);
}

//����Max�������������еĽϴ��ߣ�
int Max(int x, int y) { return (x > y ? x : y); }

template <class T>
int BinaryTree<T>::Depth(const BinTreeNode<T> *t)
{ //������tΪ���Ķ������ĸ߶�
	if (t == NULL)
		return 0;
	//�ݹ��������Ϊ�����������߶�Ϊ0
	else
		return 1 + Max(Depth(t->Lchild), Depth(t->Rchild));
}

template <class T>
BinTreeNode<T> *BinaryTree<T>::Find(BinTreeNode<T> *t, T &value)
{ //��������ҳɹ�������
	if (t == NULL || t->data == value)
		return t;
	else if (value < t->data) //���򣬼�������������
		return (Find(t->Lchild, value));
	//���򣬼�������������
	else
		return (Find(t->Rchild, value));
}

template <class T>
bool BinaryTree<T>::Insert(BinTreeNode<T> *&t, T &value)
{ //����tΪ���Ķ����������в���ֵΪvalue�Ľ��
	if (t == NULL)
	{
		t = new BinTreeNode<T>(value);
		return true;
	}
	else if (value < t->data)
		Insert(t->Lchild, value); //����ָ��
	else if (value > t->data)
		Insert(t->Rchild, value); //�Һ���ָ��
	else
		return false;
}

template <class T>
bool IsSimilar(BinTreeNode<T>* T1, BinTreeNode<T>* T2)
{
	bool leftS = false, rightS = false; //���������������ص���Ϣ

	if (T1 == NULL && T2 == NULL) //������㶼Ϊ��
		return true;
	else if (T1 == NULL || T2 == NULL) //��һ����㲻Ϊ��
		return false;
	else
	{
		int leftS = IsSimilar(T1->Lchild, T2->Lchild);  //�ݹ�������
		int rightS = IsSimilar(T1->Rchild, T2->Rchild); //�ݹ�������

		return leftS && rightS; //����������������Ϣ
	}
}

int main(void)
{
	BinTreeNode<char> *A;
	string As;
	cin >> As;
	int Ap = 0;
	A = preSet<char>(As, Ap);
	BinaryTree<char> AT(A);
	
	cout << "ǰ����������";
	AT.PreOrder(A);
	cout << endl;
	cout << "������������";
	AT.InOrder(A);
	cout << endl;
	cout << "������������";
	AT.PostOrder(A);
	cout << endl;

	return 0;
}