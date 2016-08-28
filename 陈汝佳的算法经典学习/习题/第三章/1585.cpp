#include <stdio.h>
#include <string.h>

int main()
{
	char x;
	int T,ans=0;
	scanf("%d",&T);
	getchar();
	while(T--)
	{
		ans=0;
		int i=0;
		while((x=getchar())!= '\n')
		{
			if(x=='O')
			{
				ans+= (++i);
			}
			else
			{
				i=0;
			}

		}
		printf("%d\n",ans );
	}
	return 0;
}
