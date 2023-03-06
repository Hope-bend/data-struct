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

//��������
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

//1.ͷ�巨,��������������ڵ�ĺ���,һ���������ĩβ 
ListNode* List_Headinsert(ListNode* L, int x)
{
    ListNode* newNode = new ListNode(x);     
	newNode->next = L->next; 
	L->next = newNode;
}

//2.β�巨,�ڸ�������ڵ��ĩβ�����µĽڵ� 
ListNode* List_Tailinsert(ListNode* L, int x)
{
	ListNode* newNode = new ListNode(x);
	L->next = newNode;
 }

//��������е�Ԫ�� 
void PrintList(ListNode* L)
{
    printf("����Ԫ�����£�\n");
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
	ListNode* L = new ListNode(0);//�����ͷ��� 
	PrintList(L); 
	Create_List(L);//��ʼ��һ������
	PrintList(L);
	//�������ͷ���֮��ʹ��ͷ�巨������һ���ڵ�
	List_Headinsert(L, 0);
	PrintList(L);
	//��ȡ����ĩβ�ڵ�
	ListNode* p = L;
	while(p->next)
		p = p->next;
	//β�巨�����µĽڵ�
	List_Tailinsert(p, 6);
	PrintList(L); 
	return 0;
}

