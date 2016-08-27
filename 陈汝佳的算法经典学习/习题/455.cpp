#include <stdio.h>
#include <string.h>

int main()
{
//	freopen("D:\\1.in","r",stdin);
	char mem[100];
	int x;
	scanf("%d",&x);
	while(x--)
	{
		scanf("%s",mem);
		int len=strlen(mem);
		int i,j=0,k;
		for(i=1;i<=len;i++)
			if(len%i==0){
				for(j=i;j<len;j++)
					if(mem[j]!=mem[j%i])
						break;
					if(j==len)
					 {printf("%d\n",i );break;}
			}
			if(x) printf("\n");
	}
	return 0;
}
