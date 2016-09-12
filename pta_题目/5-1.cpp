#include <stdio.h>
int findmax(int A[],int k,int *first,int *second);
int main ()
{
	int k=0,data[100990],a=0,b=0;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
		scanf("%d",&data[i]);
	printf("%d",findmax(data,k,&a,&b));
	return 0;
}
int findmax(int A[],int k,int *first,int *second)
{   int ThisSum, MaxSum;
    int i;
    ThisSum = MaxSum = 0;
    for( i = 0; i < k; i++ ) 
	{
          ThisSum += A[i];
          if( ThisSum > MaxSum )
		  {
                  MaxSum = ThisSum;
		  }
          else if( ThisSum < 0 )
		  {      
			  ThisSum = 0; 
		  }
	}
    return MaxSum;  
}