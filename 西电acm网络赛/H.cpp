#include <stdio.h>
long long int ff(long long int n)
{
	long long int x=1,y=1,z=1,temp=0,i=0;
	if(n==0||n==1||n==2) return 1;
	else{
		for(i=2;i<n;i++)
		{
			temp=x+y+z;
			x=y;
			y=z;
			z=temp;
		}
		return z;
	}
}
int main()
{
	long long int n;
	while(scanf("%lld",&n)!= EOF)
	printf("%lld\n",ff(n));
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
