#include<iostream>
using namespace std;

//�������ڵ㣬��������ʼ������
typedef struct BstNode
{
    int key;
    BstNode *lchild, *rchild, *parent;
    //��ʼ�����캯��
    BstNode(int &key): key(key), lchild(nullptr), rchild(nullptr){}
}BstNode, *BstTree;

//��ӡ������
void InOrder(BstNode* root)
{
	if(root)
	{
		InOrder(root->lchild);
		cout << root->key << " ";
		InOrder(root->rchild);
	}
}

//����ڵ�
bool Insert(BstNode*&root, int key)
{
	//������ڵ�Ϊ��ʱ��ֱ�Ӵ���Ϊ���ڵ�
	if(!root)
	{
		root = new BstNode(key);
		return true;
	}
	//��paָ�����׽ڵ�
	BstNode* pa = nullptr;
	//��p������ڵ��ƶ�
	BstNode* p = root;
	//�ҵ�Ҫ����Ľڵ�
	while(p != nullptr && p->key != key)
	{
		pa = p;
		p = p->key < key ? p->lchild : p->rchild;
	}
	//���pָ��Ľڵ��Ҫ����Ľڵ��ֵ��ͬ
	if(p->key == key)return false;
	//��ʼ��Ҫ����Ľڵ�
	p = new BstNode(key);
	//����Ҫ����ڵ�ָ��ĸ��ڵ�
	p->parent = pa;
	//�������:����һ��Ϊ��Ҷ����Ȼ�������ͬԪ�أ�����ʧ��
	pa->key > key ? pa->lchild = p : pa->rchild = p;
	return true;
}

//���Ҷ��������������ֵ
BstNode* Last(BstNode*root)
{
	while(root != nullptr && root->rchild != nullptr)
		root = root->rchild;
	return root;
}

//���Ҷ�������������Сֵ
BstNode* First(BstNode* root)
{
	while(root !=nullptr && root->lchild != nullptr)
		root = root->lchild;
	return root;
}

//����ĳһ�ڵ��ǰ��
BstNode* Prev(BstNode* root)
{
	if(root == nullptr)
		return nullptr;
	if(root->lchild != nullptr)
		return Last(root->lchild);
	//Ҫ�ҵ�ǰ���ڵ���Ҷ�ӽڵ�
	else
	{
		//�������Ҷ�ӽڵ㣬�丸�׽ڵ����ֱ��ǰ��
		//�������Ҷ�ӽڵ㣬��һ��������ֱϵ�����йص��������ڵ������ֱ��ǰ��
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
	//�������Ҷ�ӽڵ㣬�丸�׽ڵ����ֱ�Ӻ��
	//�������Ҷ�ӽڵ㣬��һ��������ֱϵ�����йص��������ڵ������ֱ�Ӻ��
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

//������������ɾ��
/*
�и�������⣬û��ɾ��Ҫɾ���Ľڵ㣬ֻ�Ǳ��λ�ø����ˣ�
���ٴ���ԭ��ɾ���Ľڵ��λ�ò���ڵ�ʱ��ֻ�ǽ�ԭ���Ľڵ�
���µĽڵ������û��ɾ��ԭ���Ľڵ�
*/
bool Remove(BstNode*& root, int key)
{
	//����Ϊ��ʱ���޷�ɾ��
	if(root == nullptr)
	 	return false;
	//����ָ��p������ͷ�ڵ��ƶ�
	BstNode* p = root;
	//�ҵ�Ҫɾ���Ľڵ�
	while(p != nullptr && p->key != key)
		p = p->key > key ? p->lchild : p->rchild;
	//���pΪ�գ�˵��û���ҵ�Ҫɾ�Ľڵ�
	if(p == nullptr)
		return false;
	//��������������Ϊ��ʱ,�ñ����൱��ɾ��ֱ�Ӻ�̽ڵ�
	if(p->lchild != nullptr && p->rchild != nullptr)
	{
		//������First����Ϊ�϶�������Ҷ�ڵ�
		BstNode* last = First(p->rchild);
		//����ڵ���
		p->key = last->key;
		p = last;
		delete p;
		return true;
	}
	/*
	//��pa�����丸�׽ڵ�
	BstNode* pa = p->parent;
	//Ҫɾ���Ľڵ�����Һ���������һ��Ϊ�գ���ʱĬ��Ϊ����֧�ڵ�
	BstNode* child = p->lchild != nullptr ? p->lchild : p->rchild;
	//�ж����Ƿ�Ϊ����֧�ڵ�
	if(child != nullptr)
		child->parent = pa;*/
		BstNode* pa = p->parent;
	//���������Ϊ��
	//������������Ϊ�յ�����Ѿ�����������
	if(p->lchild == nullptr)
	{
		pa = p->lchild;
	}
	//���������Ϊ��
	else
	{
		pa = p->rchild;
	}
	delete p;
	return true;
}























