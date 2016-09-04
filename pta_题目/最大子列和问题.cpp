#include <stdio.h>
int findmax(int A[],int k,int *first,int *second);
int main ()
{
	int k=0,data[100990],a=0,b=0,f=0,l=0;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
		{
			scanf("%d",&data[i]);
			if(data[i]<0) f++;
			if(data[i]==0) l++;
		}
	if(f==k) {printf("0 %d %d",data[0],data[k-1]);return 0;}
	else if(f+l == k) {printf("0 0 0");return 0;}
	int tem=findmax(data,k,&a,&b);
	printf("%d %d %d",tem,a,b);
	return 0;
}
int findmax(int A[],int k,int *first,int *second)
{   int ThisSum, MaxSum;
    int i,flag=A[0];
    ThisSum = MaxSum = 0;
    for( i = 0; i < k; i++ ) 
	{
          ThisSum += A[i];
          if( ThisSum > MaxSum )
		  {
		  		*first=flag;
		  		*second=A[i];
                 MaxSum = ThisSum;
		  }
          else if( ThisSum < 0 )
		  {      
		  	flag=A[i+1];
			  ThisSum = 0; 
		  }
	}
    return MaxSum;  
}
