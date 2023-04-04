#include<iostream>
using namespace std;

//建立根节点，并创建初始化函数
typedef struct BstNode
{
    int key;
    BstNode *lchild, *rchild, *parent;
    //初始化构造函数
    BstNode(int &key): key(key), lchild(nullptr), rchild(nullptr){}
}BstNode, *BstTree;

//打印二叉树
void InOrder(BstNode* root)
{
	if(root)
	{
		InOrder(root->lchild);
		cout << root->key << " ";
		InOrder(root->rchild);
	}
}

//插入节点
bool Insert(BstNode*&root, int key)
{
	//当插入节点为空时，直接创建为根节点
	if(!root)
	{
		root = new BstNode(key);
		return true;
	}
	//用pa指代父亲节点
	BstNode* pa = nullptr;
	//用p代替根节点移动
	BstNode* p = root;
	//找到要插入的节点
	while(p != nullptr && p->key != key)
	{
		pa = p;
		p = p->key < key ? p->lchild : p->rchild;
	}
	//如果p指向的节点和要插入的节点的值相同
	if(p->key == key)return false;
	//初始化要插入的节点
	p = new BstNode(key);
	//更新要插入节点指向的父节点
	p->parent = pa;
	//插入结论:插入一定为子叶，不然则存在相同元素，插入失败
	pa->key > key ? pa->lchild = p : pa->rchild = p;
	return true;
}

//查找二叉搜索树的最大值
BstNode* Last(BstNode*root)
{
	while(root != nullptr && root->rchild != nullptr)
		root = root->rchild;
	return root;
}

//查找二叉搜索树的最小值
BstNode* First(BstNode* root)
{
	while(root !=nullptr && root->lchild != nullptr)
		root = root->lchild;
	return root;
}

//查找某一节点的前驱
BstNode* Prev(BstNode* root)
{
	if(root == nullptr)
		return nullptr;
	if(root->lchild != nullptr)
		return Last(root->lchild);
	//要找的前驱节点是叶子节点
	else
	{
		//如果是右叶子节点，其父亲节点就是直接前驱
		//如果是左叶子节点，第一个与其有直系亲属有关的右子树节点就是其直接前驱
		BstNode* pa = root->parent;
		while(pa != nullptr && pa->rchild != root)
		{
			root = pa;
			pa = root->parent;
		}
		return pa;
	}
}

BstNode* Next(BstNode* root)
{
	if(root == nullptr)return nullptr;
	if(root->rchild != nullptr)
		return First(root->rchild);
	//如果是左叶子节点，其父亲节点就是直接后继
	//如果是右叶子节点，第一个与其有直系亲属有关的左子树节点就是其直接后继
	else
	{
		BstNode* pa = root->parent;
		while(pa != nullptr && pa->lchild != root)
		{
			root = pa;
			pa = root->parent;
		}
		return pa;
	}
}

//二叉搜索树的删除
/*
有个大的问题，没有删除要删除的节点，只是别的位置覆盖了，
当再次像原来删除的节点的位置插入节点时，只是将原来的节点
用新的节点替代，没有删除原来的节点
*/
bool Remove(BstNode*& root, int key)
{
	//当树为空时，无法删除
	if(root == nullptr)
	 	return false;
	//声明指针p，代替头节点移动
	BstNode* p = root;
	//找到要删除的节点
	while(p != nullptr && p->key != key)
		p = p->key > key ? p->lchild : p->rchild;
	//如果p为空，说明没有找到要删的节点
	if(p == nullptr)
		return false;
	//当左右子树都不为空时,用变相相当于删除直接后继节点
	if(p->lchild != nullptr && p->rchild != nullptr)
	{
		//可以用First，因为肯定不是子叶节点
		BstNode* last = First(p->rchild);
		//代替节点了
		p->key = last->key;
		p = last;
		delete p;
		return true;
	}
	/*
	//用pa代替其父亲节点
	BstNode* pa = p->parent;
	//要删除的节点的左右孩子至少有一个为空，暂时默认为单分支节点
	BstNode* child = p->lchild != nullptr ? p->lchild : p->rchild;
	//判断其是否为单分支节点
	if(child != nullptr)
		child->parent = pa;*/
		BstNode* pa = p->parent;
	//如果左子树为空
	//当左右子树都为空的情况已经包含在其中
	if(p->lchild == nullptr)
	{
		pa = p->lchild;
	}
	//如果右子树为空
	else
	{
		pa = p->rchild;
	}
	delete p;
	return true;
}























