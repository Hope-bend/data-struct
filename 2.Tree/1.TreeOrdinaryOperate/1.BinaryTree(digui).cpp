#include<iostream>
using namespace std;

typedef struct Node
{
	char data;
	struct Node *lchild, *rchild;
}BiTNode, *BiTree;

//���򴴽�������
void CreateBiTree(BiTree &T)
{ 
	char ch;
	cin >> ch;
	if(ch == '#')T = NULL;
	else
	{
		T = new BiTNode;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

//�������
void PreOrder(BiTree T)
{
	if(T)
	{
		cout << T->data;
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
} 



//�������
void InOrder(BiTree T)
{
	if(T)
	{
		InOrder(T->lchild);
		cout << T->data;
		InOrder(T->rchild);
	};
} 

//�������
int Depth(BiTree T)
{
	if(T == NULL)return 0;
	else
	{
		int i = Depth(T->lchild);
		int j = Depth(T->rchild);
		return i > j ? (i + 1) : (j + 1);
	}
}

int main()
{
	BiTree T;
	// cout << "���򴴽�������:";
	//   abc##de#g##f###   ���������������� 
	CreateBiTree(T);
	cout << endl;
	cout << "�������������:";
	PreOrder(T);
	cout << endl;
	// cout << "�������������:";
	InOrder(T);
	cout << endl;
	// cout << "�������:" << Depth(T) << endl;
	system("pause");
	return 0;

}






























































 






 
