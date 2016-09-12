#include <stdio.h>

long int find(long int w[],long int v[],int n,int C);
long int max(long int a,long int b);
int main()
{
	int n,W;
	int i=0,j=0;
	while(scanf("%d%d",&n,&W) != EOF)
	{
	    long int v[1000]={0},w[1000]={0};
	    long int val=0;
	    for(i=1;i<n+1;i++)	
	       scanf("%ld%ld",&w[i],&v[i]);
	val=find(w,v,n,W);	
	printf("%ld\n",val);
	}
	return 0;
}
long int find(long int w[],long int v[],int n,int C)
{
	int i,j;
   long int V[100][100]={0};
	for(i=0;i<=n;i++)
	    for(j=0;j<=C;j++)
	       V[i][j]=0;
	  for(i=1;i<=n;i++)
   	  for(j=1;j<=C;j++)
	       if(j<w[i]) V[i][j]=V[i-1][j];
	       else V[i][j]=max(V[i-1][j],V[i-1][j-w[i]]+v[i] );
	return V[n][C] ;	
}
long int max(long int a,long int b)
{
   return a>b?a:b;	
	}
	
	
	
