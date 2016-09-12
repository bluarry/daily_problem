#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
//#define LOCAL
int map[16][11]={0},tar[5][5]={0};

struct node
{
	int hehe;
	int x,y;
}kuai[5];

bool cmp(struct node a,struct node b)
{
return  a.x>b.x;
}

int main()
{	
	#ifdef LOCAL
	freopen("D:\\1.in","r",stdin);
	#endif
	int start=-1;
	for(int i=1;i<=15;i++)
		for(int j=1;j<=10;j++)
			cin >> map[i][j];
		int k=1,min_cow=11,min_line=11;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
			{
				cin >> tar[i][j];
				if(tar[i][j]==1)
				{
					kuai[k].x=i;
					kuai[k].y=j;
					if(j<min_cow) {min_cow =j;min_line=i;}
					k++;
				}
			}
		cin >> start;
		
		start=start+min_cow-1;


		int a=0,b=0;//将块导入,并计算坐标
		for(int i=1;i<=4;i++)
			{	
				a=kuai[i].x - min_line;
				b=kuai[i].y - min_cow;
				map[min_line+a][start+b]=1;
				kuai[i].x=min_line+a;
				kuai[i].y=start+b;
			}

		for(int i=1;i<=4;i++)
			if(map[kuai[i].x+1][kuai[i].y]==0)
				kuai[i].hehe=1;
			else
				kuai[i].hehe=0;
		
		sort(kuai+1,kuai+5,cmp);

		int flag=1;
		while(1)
		{
			for(int i=1;i<=4;i++)
				if( (kuai[i].x+1) >15 || (map[kuai[i].x+1][kuai[i].y]==1 && kuai[i].hehe==1))
					flag=0;
				if(flag)
				{
					for(int i=1;i<=4;i++)
					{
						map[kuai[i].x][kuai[i].y]=0;
						kuai[i].x++;
						map[kuai[i].x][kuai[i].y]=1;
					}
				}
				else
					break;
		}




//打印地图
		for(int i=1;i<=15;i++)
			for(int j=1;j<=10;j++)
			j==10?cout << map[i][j] << endl:cout << map[i][j]<<" ";


	return 0;
}
