#include <stdio.h>
#include <string.h>

int main()
{
	int T;
	scanf("%d",&T);
	int count[10];
	while(T--)
	{
		int x; scanf("%d",&x);
		memset(count,0,sizeof(count));
		for(int i=1;i<=x;i++)
		{
			int j=i;
			while(j)
			{
				count[j%10]++;
				j/=10;
			}
		}
		for(int i=0;i<10;i++)
			if(i) printf(" %d",count[i]);
			else printf("%d",count[i] );
			printf("\n");


	}




	return 0;
}
