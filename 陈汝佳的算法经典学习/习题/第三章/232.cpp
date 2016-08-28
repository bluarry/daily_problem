#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

char map[11][11];
int head[11][11];
int main()
{
	int r,c,T=0;
	while(scanf("%d%d",&r,&c),r)
	{
		int t=0;
		getchar();
		memset(head,0,sizeof(head));
		for(int i=1;i<=r;i++)
		{	for(int j=1;j<=c;j++)
			{
				map[i][j]=getchar();
				if(  (map[i][j]!='*') &&(i==1|| j==1 ||  map[i-1][j]=='*' ||  map[i][j-1]=='*' ) )
					head[i][j]= ++t;
				else 
				head[i][j]=0;
			}
			getchar();
		}
		if(T)
		printf("\npuzzle #%d:\n",++T);
		else
		printf("puzzle #%d:\n",++T);
		printf("Across\n");
/*
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
			{
				if(j==c) printf("%c\n", map[i][j]);
				else
					printf("%c ", map[i][j]);
			}


*/
		int k=0,i,j;
		for(i=1;i<=r;i++)
		{
			k=1;
			while(k<=c)
			{
				if(head[i][k])
				{
					printf("%3d.",head[i][k]);
					while(k<=c && map[i][k]!='*')
						printf("%c",map[i][k++]);
					putchar('\n');
				}
				else
					k++;
			}
		}

		for(i=1;i<=r;i++)
			for(j=1;j<=c;j++)
			{


				
			}



















	}


	return 0;
}
