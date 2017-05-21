#include <stdio.h>
int main()
{
	long int a,x,y;
	while(3==scanf("%d%d%d",&x,&y,&a))	
	{
		if(a%(x+y)==0)
			printf("light\n");
		else if(a%(x+y)<=x)
			printf("wanshen\n");
		else if(a%(x+y)>x)
		printf("light\n");
	}
	
	
	
	
	return 0;
}
