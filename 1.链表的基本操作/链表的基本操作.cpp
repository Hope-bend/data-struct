#include<iostream>
using namespace std; 

typedef struct ListNode
{
	int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//创建链表
ListNode* Create_List(ListNode* L)
{
	ListNode* p = L;
	int q[] = {1, 2, 3, 4, 5};

	for(int i = 0; i < 5; i++)
	{
		int x = q[i];
		ListNode* s	= new ListNode(x);
		p->next = s;
		p = p->next;		
	}
 	return L;
} 

//1.头插法,插入所给定链表节点的后面,一般是链表的末尾 
ListNode* List_Headinsert(ListNode* L, int x)
{
    ListNode* newNode = new ListNode(x);     
	newNode->next = L->next; 
	L->next = newNode;
}

//2.尾插法,在给定链表节点的末尾插入新的节点 
ListNode* List_Tailinsert(ListNode* L, int x)
{
	ListNode* newNode = new ListNode(x);
	L->next = newNode;
 }

//输出链表中的元素 
void PrintList(ListNode* L)
{
    printf("链表元素如下：\n");
    ListNode* p = L;
    while(p)
    {
        printf("%d ",p->val);
        p = p->next;
    }
    printf("\n");
}

int main()
{
	ListNode* L = new ListNode(0);//链表的头结点 
	PrintList(L); 
	Create_List(L);//初始化一条链表
	PrintList(L);
	//在链表的头结点之后使用头插法，插入一个节点
	List_Headinsert(L, 0);
	PrintList(L);
	//获取链表末尾节点
	ListNode* p = L;
	while(p->next)
		p = p->next;
	//尾插法插入新的节点
	List_Tailinsert(p, 6);
	PrintList(L); 
	return 0;
}

