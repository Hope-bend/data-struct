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
	//0--���ӣ�1--�Һ��ӣ�2������ɣ�"#"�����
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
			//������� 
			else if(ch[i] == '#' && st->tag[st->top - 1] == 0)
			{
				p1->lchild = NULL;
				st->tag[st->top - 1] = 1;//������� 
			}
			//������� 
			else if(ch[i] == '#' && st->tag[st->top - 1]== 1)
			{
				p1->lchild = NULL;
				st->tag[st->top - 1] = 2;//������������ɣ��������С��������� 
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
			//�Ƿ��ջ�������������������ѽ���ʱ����ջ 
			while(st->tag[st->top - 1] == 2)
			{
				st->tag[st->top - 1] = 0;
				p1 = pop(st);
				//�������һ���ڵ�����������û�д˾䣬�ᵼ��ջ��topԽ�� 
				if(st->top)p1 = top(st);
				else break;
				//˵����ʱ�Ľڵ���������Ѵ��ڣ����ҵ�ǰָ���Ǵ���һ�������������Ľڵ㣬��������Ҳ���� 
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

//�ݹ�������� 
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
	printf("���������");
	inorprint(root);
	printf("\n");
	return 0;

}













































 
