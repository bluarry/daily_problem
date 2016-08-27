#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	long int data;
	node *next;
}*files;
files readfi(int n);
int main()
{
	int n=0,k=0,i=0,j=0,m=0;
	long int temp=0;
	files head=NULL,a=NULL,d=NULL,c=NULL;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		head=readfi(n);
//	
	a=head->next;
	for(;a->next!=NULL;)
		{
			printf("%ld ",a->data);
			a=a->next;
		}
		printf("%ld\n",a->data);
//
		for(i=0,a=head->next;i<=n;i++)
		{
				d=a;
			for(j=i,c=d;j<n;j++)
			{
					
				if(a->data > c->data)
				{
					temp=a->data;
					a->data=c->data;
					c->data=temp;
				}
				c=c->next;
			}
			a=d->next;
		}
	//	a=head->next;
		
//	
	a=head->next;
	for(;a->next!=NULL;)
		{
			printf("%ld ",a->data);
			a=a->next;
		}
		printf("%ld\n",a->data);
//
		
		
//		
		
		
		
		
		
		
		
		
		
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
	
	return 0;
}

files readfi(int n)
{
	int i=0;
	files a=(node *)malloc(sizeof( node )),b=NULL,head=NULL,c=NULL,d=NULL;
	for(i=0;i<n;i++)
		{
		b=(node *)malloc(sizeof( node ));
		scanf("%ld",&b->data);
		a->next=b;
		if(i==0) head=a;
		a=a->next;
	}
		a->next=NULL;
	return head;
}
