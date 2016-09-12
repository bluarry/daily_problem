#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
/*************************单链表及其操作集************************/
#define Status int
#define ERROR -1
#define OK 1
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

//用e返回第i个元素
Status GetElem(LinkList L,int i,ElemType &e){
	LinkList p=L->next;
	int j=1;
	while(p&&j<i)
		p=p->next,++j;
	if(!p||j>i) return ERROR;
	e=p->data;
	return OK;
}
//插入元素e
Status ListInsert(LinkList &L,int i,ElemType e)
{
	LinkList p=L,s;
	int j=0;
	while(p&&j<i-1)
	{
		p=p->next;
		++j;
	}
	if(!p || j>i-1)
		return ERROR;
	s=(LinkList)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}
//删除第i个元素，并用e返回其值
Status ListDelete(LinkList &L,int i,ElemType &e){
	LinkList p=L,q;
	int j=0;
	while(p->next && j<i-1)
	{
		p=p->next;
		++j;
	}
	if(!(p->next) || j>i-1)
		return ERROR;
	q=p->next; p->next=q->next;
	e=q->data; free(q);
	return OK;
}

//建立带头结点的单链表  尾插法
void CreatList(LinkList &L,int n)
{
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	for(int i=n;i>0;i--)
	{
		LinkList p=(LinkList)malloc(sizeof(LNode));
		cin >> p->data;
		p->next=L->next;
		L->next=p;
	}
}














