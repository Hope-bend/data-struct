#include<iostream>
using namespace std;

char ch[] = "ABDH#K###E##CFI###G#J##";

#define MAX 1000

typedef struct Node
{
	char info;
	struct Node *lchild, *rchild;	
}Tree;

//栈的结构体声明 
typedef struct stack_1
{
	Tree* a[MAX];
	int tag[MAX];
	int top;
}stack;

//栈顶元素的弹出 
Tree* pop(stack* st)
{
	if(st->top)
	{
		st->top--;
		return st->a[st->top];
	}
	else return NULL;
}

//入栈
void push(stack* st, Tree* t)
{
	st->a[st->top] = t;
	st->top++;
}

//获取栈顶元素 
Tree* top(stack* st)
{
	if(st->top)return st->a[st->top-1];
	else return NULL;
}

Tree* create()
{
	//0--左孩子，1--右孩子，2建树完成，"#"代表空
	stack A;
	stack* st;
	st = &A;
	Tree* root;
	Tree *p1, *p2;
	int i = 0;
	st->top = 0;
	while(ch[i] != '\0')
	{
		if(i == 0)//建立根节点 
		{
			root = new 	Tree;
			root->info = ch[i];
			root->lchild = NULL;
			root->rchild = NULL;
			p1 = root;
			push(st, p1);
			st->tag[st->top - 1] = 0;
			
		}
		else//非根节点 
		{
			//建左树 
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
			//左树完成 
			else if(ch[i] == '#' && st->tag[st->top - 1] == 0)
			{
				p1->lchild = NULL;
				st->tag[st->top - 1] = 1;//左树完成 
			}
			//右树完成 
			else if(ch[i] == '#' && st->tag[st->top - 1]== 1)
			{
				p1->lchild = NULL;
				st->tag[st->top - 1] = 2;//右子树构建完成，即：这棵小树构建完成 
			}
			//建右树
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
			//是否出栈操作，当左右子树都已建立时，出栈 
			while(st->tag[st->top - 1] == 2)
			{
				st->tag[st->top - 1] = 0;
				p1 = pop(st);
				//避免最后一个节点误操作，如果没有此句，会导致栈的top越界 
				if(st->top)p1 = top(st);
				else break;
				//说明此时的节点的左子树已存在，并且当前指针是从下一右子树返上来的节点，即右子树也存在 
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

//递归中序遍历 
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
	printf("后序遍历：");
	inorprint(root);
	printf("\n");
	return 0;

}













































 
