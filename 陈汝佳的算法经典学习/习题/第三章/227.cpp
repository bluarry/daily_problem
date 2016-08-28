#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char map[6][6];

int main()
{
//	freopen("D:\\1.in","r",stdin);
	int T=0;
	while(1)
	{
		int i,j,k,x=0,y=0;
		for(i=1;i<=5;i++)
		{	for(j=1;j<=5;j++)
			{
				map[i][j]=getchar();
				if(map[1][1]=='Z') return 0;
				if(map[i][j]==' '){x=i,y=j;}
			}
			getchar();
		}
			if(T)
			printf("\nPuzzle #%d:\n",++T);
			else
			printf("Puzzle #%d:\n",++T);
			
			char c;
			while( (c=getchar()) != '0'){
				if(c=='A')
				{
					if(x-1 < 1)
					{
						printf("This puzzle has no final configuration.\n");
						while((c=getchar()) != '0');
						c='1';
						break;
					}
					swap(map[x][y],map[x-1][y]);
					x--;
				}
				else if(c=='B')
				{
					if(x+1 > 5)
					{
						printf("This puzzle has no final configuration.\n");
						while((c=getchar()) != '0') ;
						c='1';
						break;
					}
					swap(map[x][y],map[x+1][y]);
					x++;
				}
				else if(c=='L')
				{
					if( y-1 < 1)
					{
						printf("This puzzle has no final configuration.\n");
						while((c=getchar()) != '0');
						c='1';
						break;
					}
					swap(map[x][y],map[x][y-1]);
					y--;
				}
				else if(c=='R')
				{
					if(y+1 > 5)
					{
						printf("This puzzle has no final configuration.\n");
						while((c=getchar()) != '0');
						c='1';
						break;
					}
					swap(map[x][y],map[x][y+1]);
					y++;
				}
				else 
					continue;
			}
			
			getchar();

			if(c=='0')
			{
				for(i=1;i<=5;i++)
					for(j=1;j<=5;j++)
					{
						if(j!=5)
						printf("%c ",map[i][j]);
						else 
							printf("%c\n",map[i][j]);
					}
					
			}
	}
}
