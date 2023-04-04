/*
#include<iostream>
using namespace std;

char ch[] = "ABDH#K###E##CFI###G#J##";

#define MAX 1000

typedef struct Node
{
	char info;
	struct Node *lchild, *rchild;	
}Tree;

//ջ�Ľṹ������ 
typedef struct stack_1
{
	Tree* a[MAX];
	int tag[MAX];
	int top;
}stack;

//ջ��Ԫ�صĵ��� 
Tree* pop(stack* st)
{
	if(st->top)
	{
		st->top--;
		return st->a[st->top];
	}
	else return NULL;
}

//��ջ
void push(stack* st, Tree* t)
{
	st->a[st->top] = t;
	st->top++;
}

//��ȡջ��Ԫ�� 
Tree* top(stack* st)
{
	if(st->top)return st->a[st->top-1];
	else return NULL;
}

Tree* create()
{
	//0--���ӣ�1--�Һ��ӣ�2������ɣ�?"#"������
	stack A;
	stack* st;
	st = &A;
	Tree* root;
	Tree *p1, *p2;
	int i = 0;
	st->top = 0;
	while(ch[i] != '\0')
	{
		if(i == 0)//�������ڵ� 
		{
			root = new 	Tree;
			root->info = ch[i];
			root->lchild = NULL;
			root->rchild = NULL;
			p1 = root;
			push(st, p1);
			st->tag[st->top - 1] = 0;
			
		}
		else//�Ǹ��ڵ� 
		{
			//������ 
			if(ch[i] != '#' && st->tag[st->top - 1] == 0)
			{
				p2 = new Tree;
				p2->info = ch[i];
				p2->lchild = NULL;
				p2->rchild = NULL;
				push(st, p2);
				p1->lchild = p2;
				p1 = p2;
				st->tag[st->top - 1] = 0;
			}
			//�������? 
			else if(ch[i] == '#' && st->tag[st->top - 1] == 0)
			{
				p1->lchild = NULL;
				st->tag[st->top - 1] = 1;//�������? 
			}
			//�������? 
			else if(ch[i] == '#' && st->tag[st->top - 1]== 1)
			{
				p1->lchild = NULL;
				st->tag[st->top - 1] = 2;//������������ɣ��������С���������? 
			}
			//������
			else if(ch[i] != '#' && st->tag[st->top - 1] == 1)
			{
				p2 = new Tree;
				p2->info = ch[i];
				p2->lchild = NULL;
				p2->rchild = NULL;
				push(st, p2);
				p1->rchild = p2;
				p1 = p2;
				st->tag[st->top - 1] = 0;
			}
			//�Ƿ��ջ�������������������ѽ���ʱ�����? 
			while(st->tag[st->top - 1] == 2)
			{
				st->tag[st->top - 1] = 0;
				p1 = pop(st);
				//�������һ���ڵ�����������û�д˾䣬�ᵼ��ջ��topԽ�� 
				if(st->top)p1 = top(st);
				else break;
				//˵����ʱ�Ľڵ���������Ѵ��ڣ����ҵ�ǰָ���Ǵ���һ�������������Ľڵ㣬��������Ҳ����? 
				if(st->tag[st->top - 1] == 1)
					st->tag[st->top - 1] = 1; 
			}
			if(p1->lchild != NULL || st->tag[st->top - 1] == 1)
				st->tag[st->top - 1] = 1;
		}
		i++;
	}
	return root;
}

//�ݹ��������? 
void inorprint(Tree* t)
{
	Tree* p1;
	p1 = t;
	if(p1)
	{
		inorprint(p1->lchild);
		printf("%c->",  p1->info);
		inorprint(p1->rchild);
	}
}

int main()
{
	Tree* root;
	root = create();
	cout << 111 << endl;
	printf("前序遍历�?");
	inorprint(root);
	printf("\n");
	return 0;

}*/

/*
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//创建结构�?
typedef struct Node
{
	char info;
	Node *lchild, *rchild;
	Node():lchild(nullptr), rchild(nullptr){}
	Node(char val):info(val), lchild(nullptr), rchild(nullptr){}
	~Node(){}
}Tree;*/

/*
//创建树结构体
typedef struct Tree
{
	Node* root;
	Tree():root(nullptr){}
	Tree(Node* t):root(t){}
	~Tree(){}
};*/


/*
//使用前序遍历迭代法创建二叉树
Tree* create(const char*&str)
{
	stack<Tree> A;
	stack<Tree*> st;
	vector<int> tag;
	Tree* root;
	Tree *p1, *p2;
	int i = 0;
	while(str[i] != '\0')
	{
		//建立根节�?
		if(i == 0)
		{
			//初始化根节点
			root = new Tree(str[i]);
			//令p1代替根节点移�?
			p1 = root;
			//存放树的指针的队�?
			st.push(p1);
			//标记�?0为左树为空，1为右树为空，2为建树完�?
			tag.push_back(0);
		}
		else
		{
			//输入不为空，创建左子树的节点
			if(str[i] !='#' && tag.back() == 0)
			{
				p2 = new Tree(str[i]);
				st.push(p2);
				//令p1的左孩子为p2
				p1->lchild = p2;
				p1 = p2;
				tag.push_back(0);
			}
			//左子树为�?
			else if(str[i] == '#' && tag.back() == 0)
			{
				tag[tag.size() - 1] = 1;
			}
			//右子树为�?,小树建立完成
			else if(str[i] == '#' && tag.back() == 1)
			{
				tag[tag.size() - 1] = 2;
			}
			//输入不为空，创建右子树的节点
			else if(str[i] != '#' && tag.back() == 1)
			{
				p2 = new Tree(str[i]);
				st.push(p2);
				p1->lchild = p2;
				p1 = p2;
				tag.push_back(0);
			}
			while(tag.back() == 2)
			{
				tag.pop_back();
				st.pop();
				//不断更新p1所指向的节�?
				if(tag.back() != 0)
				{
					
					tag[tag.size() - 1] = 2;
				}
				else
				{
					p1 = st.top();
					tag[tag.size() - 1] = 1;
				}
			}
		}
		i++;
	}
	return root;

}

//前序遍历
void inorprint(Tree* t)
{
	Tree* p1;
	p1 = t;
	if(p1)
	{
		inorprint(p1->lchild);
		printf("%c->",  p1->info);
		inorprint(p1->rchild);
	}
}


int main()
{
	// stack<int> A;
	// A.push(1);
	// cout << A.size() << A.top() << endl;
	// const char*st = "123456789\0";
	// cout << *st++ << " " << *st; 
	// return 0;
	Tree* root;
	//测试用例
	const char* str = "ABDH#K###E##CFI###G#J##";
	root = create(str);
	cout << 111 << endl;
	printf("前序遍历�?");
	inorprint(root);
	printf("\n");
	return 0;
}*/











































 
