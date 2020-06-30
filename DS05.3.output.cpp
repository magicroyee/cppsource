#include <iostream>
#include <string>
using namespace std;

template <class T>
class BinTreeNode
{
public:
	T data;					//数据域
	BinTreeNode<T> *Lchild; //左孩子指针
	BinTreeNode<T> *Rchild; //右孩子指针
							// 构造无值结点，无左右子树
	BinTreeNode() : Lchild(NULL), Rchild(NULL) {}
	//构造有值结点，无左右子树
	BinTreeNode(T &value) : data(value), Lchild(NULL), Rchild(NULL) {}
	//构造有值、有左右子树的结点
	BinTreeNode(T &value, BinTreeNode<T> *left, BinTreeNode<T> *right)
		: data(value), Lchild(left), Rchild(right) {}
	//修改结点数据值
	void SetData(T &value) { data = value; }
	//删除当前结点的左右子树
	void release();
	//修改结点左孩子指针
	void SetLeft(BinTreeNode<T> *L);
	//修改结点右孩子指针
	void SetRight(BinTreeNode<T> *R);
	//复制以当前结点为根的二叉树
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
		Lchild->release(); //递归调用释放左子树
		delete Lchild;
		Lchild = NULL;
	}
	if (Rchild != NULL)
	{
		Rchild->release(); //递归调用释放右子树
		delete Rchild;
		Rchild = NULL;
	}
}

template <class T>
void BinTreeNode<T>::SetLeft(BinTreeNode<T> *L)
{
	Lchild->release(); //释放原来的左子树
	delete Lchild;	   //释放左子树的根结点
	Lchild = L;		   //修改左指针
}

template <class T>
void BinTreeNode<T>::SetRight(BinTreeNode<T> *R)
{
	Rchild->release(); //释放原来的右子树
	delete Rchild;	   //释放右子树的根结点
	Rchild = R;		   //修改指右指针
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
	//构造函数
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
	//析构函数
	~BinaryTree()
	{
		root->release();
		delete root;
		root = NULL;
	}
	//判二叉树空否，若二叉树为空，返回1，否则返回0
	bool IsEmpty()
	{
		return root == NULL;
	}
	//取根
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

//先序遍历以current为根的子树，递归函数
template <class T>
void BinaryTree<T>::PreOrder(BinTreeNode<T> *current)
{
	if (current != NULL)
	{
		cout << current->data << " ";	   //访问根结点,用输出语句暂代
		PreOrder(current->Lchild); //先序遍历左子树
		PreOrder(current->Rchild); //先序遍历右子树
	}
}

//中序遍历以current为根的子树，递归函数
template <class T>
void BinaryTree<T>::InOrder(BinTreeNode<T> *current)
{
	if (current != NULL) //current==NULL为递归终止条件
	{
		InOrder(current->Lchild); //中序遍历左子树
		cout << current->data << " ";	  //访问根结点，用输出语句暂代
		InOrder(current->Rchild); //中序遍历右子树
	}
}

//后序遍历以current为根的子树，递归函数
template <class T>
void BinaryTree<T>::PostOrder(BinTreeNode<T> *current)
{
	if (current != NULL) //current==NULL是递归终止条件
	{
		PostOrder(current->Lchild); //后序遍历左子树
		PostOrder(current->Rchild); //后序遍历右子树
		cout << current->data << " ";		//访问根结点, 用输出语句代
	}
}

template <class T>
int BinaryTree<T>::Size(const BinTreeNode<T> *t)
{ //计算以t为根的二叉树的结点个数
	if (t == NULL)
		return 0;
	//递归结束条件为空树，结点个数为0
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

//其中Max函数是求两者中的较大者：
int Max(int x, int y) { return (x > y ? x : y); }

template <class T>
int BinaryTree<T>::Depth(const BinTreeNode<T> *t)
{ //计算以t为根的二叉树的高度
	if (t == NULL)
		return 0;
	//递归结束条件为空树，空树高度为0
	else
		return 1 + Max(Depth(t->Lchild), Depth(t->Rchild));
}

template <class T>
BinTreeNode<T> *BinaryTree<T>::Find(BinTreeNode<T> *t, T &value)
{ //空树或查找成功，返回
	if (t == NULL || t->data == value)
		return t;
	else if (value < t->data) //否则，继续查找左子树
		return (Find(t->Lchild, value));
	//否则，继续查找右子树
	else
		return (Find(t->Rchild, value));
}

template <class T>
bool BinaryTree<T>::Insert(BinTreeNode<T> *&t, T &value)
{ //在以t为根的二叉排序树中插入值为value的结点
	if (t == NULL)
	{
		t = new BinTreeNode<T>(value);
		return true;
	}
	else if (value < t->data)
		Insert(t->Lchild, value); //左孩子指针
	else if (value > t->data)
		Insert(t->Rchild, value); //右孩子指针
	else
		return false;
}

template <class T>
bool IsSimilar(BinTreeNode<T>* T1, BinTreeNode<T>* T2)
{
	bool leftS = false, rightS = false; //用来接受子树返回的信息

	if (T1 == NULL && T2 == NULL) //两个结点都为空
		return true;
	else if (T1 == NULL || T2 == NULL) //有一个结点不为空
		return false;
	else
	{
		int leftS = IsSimilar(T1->Lchild, T2->Lchild);  //递归左子树
		int rightS = IsSimilar(T1->Rchild, T2->Rchild); //递归右子树

		return leftS && rightS; //返回两个子树的信息
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
	
	cout << "前序遍历结果：";
	AT.PreOrder(A);
	cout << endl;
	cout << "中序遍历结果：";
	AT.InOrder(A);
	cout << endl;
	cout << "后序遍历结果：";
	AT.PostOrder(A);
	cout << endl;

	return 0;
}