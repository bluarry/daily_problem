#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef int Elemtype;
typedef struct Lnode{
	int id;
	Elemtype data;
	struct Lnode *next;
}Lnode,*list;

int n;


void creatlist(list &L,int m){
	int i=1;
	cout << "������������";
	cin >> n;
	cout << "����������ÿ������������(�ÿո����): ";
	list head;
	L=(Lnode *)malloc(sizeof(Lnode));
	head=L; L->id=1;cin >> L->data;

	for(int i=2;i<=n;i++)
	{
		list p=(Lnode *)malloc(sizeof(Lnode));
		p->id=i;
		cin >> p->data;
		L->next=p;
		L=L->next;
	}
	L->next=head;
	L=L->next;
}

void delete_L(list &L)
{
	if(L->next==L) 
	{
		free(L);
		L=NULL;
		return;
	}
	list p=L->next;
	while(p->next != L)p=p->next;
	list q;
	q=L;
	p->next=L->next;
	L=L->next;
	free(q);
}

int main()
{
	int m;
	cout << "������m�ĳ�ֵ: ";
	cin >> m;

	list L;
	creatlist(L,m);
	cout << "����˳��Ϊ: ";
	int j=1;
	while(L!=NULL)
	{
		for(j=1;j<m;j++)
			L=L->next;
		cout << L->id << " ";
		m=L->data;
		delete_L(L);
	}
	return 0;
}









