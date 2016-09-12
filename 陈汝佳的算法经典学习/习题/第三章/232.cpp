#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
using namespace std;

typedef struct _node  
{  
    int  id;  
    char str[12];  
}node;  

int cmp(node a, node b)  
{  
    return a.id < b.id;  
}    
node data[101];
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



/*
    printf("Down\n");  
        int count = 0;  
        for (int i = 0; i < column; ++ i) {  
            int move = 0;  
            while (move < row) {  
                if (size[move][i]) {  
                    data[count].id = size[move][i];  
                    int save = 0;  
                    while (move < row && maps[move][i] != '*')  
                        data[count].str[save ++] = maps[move ++][i];  
                    data[count ++].str[save ++] = 0;  
                }else move ++;  
            }  
        }  
        sort(data, data+count, cmp);  
        for (int i = 0; i < count; ++ i)  
            printf("%3d.%s\n",data[i].id, data[i].str);  
*/
        printf("Down\n"); 
        int count=0;
		for(i=1;i<=c;i++)
			{
				int k=1;
					while(k<=r)
					{	
						if(head[k][i])
						{
							data[count].id=head[k][i];
							int s=0;
							while(k<=r && map[k][i] != '*')
								data[count].str[s++]=map[k++][i];
							data[count++].str[s++]=0;
						}
						else
							k++;
					}
			}
			 sort(data, data+count, cmp);  

			for (int i = 0; i < count; ++ i)  
            printf("%3d.%s\n",data[i].id, data[i].str); 

	}
	return 0;
}
