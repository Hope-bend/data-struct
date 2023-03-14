#include<iostream>
using namespace std;

typedef struct Node
{
	char data;
	struct Node *lchild, *rchild;
}BiTNode, *BiTree;

//先序创建二叉树
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

//先序遍历
void PreOrder(BiTree T)
{
	if(T)
	{
		cout << T->data;
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
} 



//中序遍历
void InOrder(BiTree T)
{
	if(T)
	{
		InOrder(T->lchild);
		cout << T->data;
		InOrder(T->rchild);
	};
} 

//树的深度
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
	// cout << "先序创建二叉树:";
	//   abc##de#g##f###   创建二叉树的用例 
	CreateBiTree(T);
	cout << endl;
	cout << "先序遍历二叉树:";
	PreOrder(T);
	cout << endl;
	// cout << "中序遍历二叉树:";
	InOrder(T);
	cout << endl;
	// cout << "树的深度:" << Depth(T) << endl;
	system("pause");
	return 0;

}






























































 






 
