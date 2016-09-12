/*
设计函数分别求两个一元多项式的乘积与和。
输入格式:
输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入
一个多项式非零项系数和指数
（绝对值均为不超过1000的整数）。数字间以空格分隔。
输出格式:
输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。
数字间以空格分隔，但
结尾不能有多余空格。零多项式应输出0 0。
输入样例:

4 3 4 -5 2 6 1 -2 0
3 5 20 -7 4 3 1
输出样例:

15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0
*/
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node *lnode;
typedef struct node{
	int base;
	int pow;
	node *next;
}node;


void multiplication(lnode ta,int n,lnode tb,int m);
lnode addition(lnode ta,lnode tb);
int main()
{
	lnode ta=(lnode )malloc(sizeof(node)),tb=(lnode )malloc(sizeof(node)),tta,ttb,head_ta,head_tb,result;
	ta->next=NULL,tb->next=NULL;
	int n,m,i=0,j=0,k=0;
	scanf("%d",&n);
	for(i=0,head_ta=ta;i<n;i++)
	{
		tta=(lnode )malloc(sizeof(node));
		scanf("%d %d",&tta->base,&tta->pow);
		ta->next=tta;
		ta=ta->next;
		if(i==n-1)ta->next=NULL;
	}

	fflush(stdin);
	scanf("%d",&m);
	for(i=0,head_tb=tb;i<m;i++)
	{
		ttb=(lnode )malloc(sizeof(node));
		scanf("%d %d",&ttb->base,&ttb->pow);
		tb->next=ttb;
		tb=tb->next;
		if(i==m-1)tb->next=NULL;
	}
	if(m==0 && n == 0 ){printf("0 0\n0 0\n");return 0;}
	//**************************************************乘法
	multiplication(head_ta->next,n,head_tb->next,m);
	//********************************************************加法
	head_ta= addition(head_ta->next,head_tb->next);
	for(i=0,result=head_ta->next;result;i++)
	{
		if(i==0)printf("%d %d",result->base,result->pow);
		else printf(" %d %d",result->base,result->pow);
		result=result->next;
	}
		printf("\n");
	//*******************************************************

	return 0;
}
lnode addition(lnode ta,lnode tb)
{
	lnode result=(lnode)malloc(sizeof(node)),result_head,temp,ta_h=ta,tb_h=tb;
	result_head=result;
	int i=0,max=0,min=0,j=0,k=0;
	while(ta_h!=NULL&&tb_h!=NULL)
	{
		if(ta_h->pow > tb_h->pow) k=1;
		else if(ta_h->pow == tb_h->pow) k=2;
		else k=3;
		switch(k)
		{
			case 1:
					//
					temp=(lnode)malloc(sizeof(node));
					temp->base = ta_h->base;
					temp->pow = ta_h->pow;
					result->next=temp;
					result=temp;
					//
					ta_h=ta_h->next;
			case 2:
					j=ta_h->base + tb_h->base;
					if(j != 0)
					{
						//
					temp=(lnode)malloc(sizeof(node));
					temp->base = j;
					temp->pow = ta_h->pow;
					result->next=temp;
					result=temp;
					//
					}
					ta_h=ta_h->next;
					tb_h=tb_h->next;
					break;
			case 3:
					//
					temp=(lnode)malloc(sizeof(node));
					temp->base = tb_h->base;
					temp->pow = tb_h->pow;
					result->next=temp;
					result=temp;
					//
					tb_h=tb_h->next;
					break;
		}
	}	
		while(tb_h!=NULL)
		{
			
			temp=(lnode)malloc(sizeof(node));
			temp->base = tb_h->base;
			temp->pow = tb_h->pow;
			result->next=temp;
			result=temp;
			//
			tb_h=tb_h->next;
		}
		while(ta_h!=NULL)
		{
			
			temp=(lnode)malloc(sizeof(node));
			temp->base = ta_h->base;
			temp->pow = ta_h->pow;
			result->next=temp;
			result=temp;
			//
			ta_h=ta_h->next;
		}
		result->next=NULL;
	
	return result_head;
	//输出结果
	
}

/*
typedef struct node *lnode;
typedef struct node{
	int base;
	int pow;
	node *next;
}node;
*/

void multiplication(lnode ta,int n,lnode tb,int m)
{
	lnode temp,ta_h=ta,tb_h=tb,tep;
	lnode result=(lnode)malloc(sizeof(node)),result_head;
	lnode last=(lnode)malloc(sizeof(node)),last_head; 
	
	result->next=NULL; last->next=NULL;
	result_head=result;last_head=last;
	
	if(ta==NULL || tb==NULL ) {printf("0 0\n");return;}
	//把ta_h的每一项乘到tb_h
	ta=ta_h;
	while(ta)
	{
		result=result_head;
		tb=tb_h;
		while(tb)
		{
			temp=(lnode)malloc(sizeof(node));
			temp->base=ta->base * tb->base;
			temp->pow=ta->pow + tb->pow;
			temp->next=NULL;
			result->next=temp;
			result=result->next;
			tb=tb->next;
		}
		
		last_head=addition(last_head->next,result_head->next);

		result=result_head->next;
		result_head->next=NULL;
		while(result)
		{
			tep=result;
			free(tep);
			result=result->next;
		}
		ta=ta->next;
	}
	
	for(last=last_head->next;last;last=last->next)
	{
		if(last->next)
			printf("%d %d ",last->base,last->pow);
		else
			printf("%d %d\n", last->base,last->pow);
	}
}
