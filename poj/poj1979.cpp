//#define LOCAL
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char map[21][21];
int vis[21][21];
int c,r;
int dir_x[]={1,0,-1,0};
int dir_y[]={0,1,0,-1};
void bfs(int x,int y){
	if(x<1 || x>r) return ;
	if(y<1||y>c) return ;
	if(map[x][y]=='#') return;

	if(vis[x][y])
		return ;
	else
		vis[x][y]=1;



	for(int i=0;i<4;i++)
	{
		int xx,yy;
		xx=x+dir_x[i];
		yy=y+dir_y[i];
		bfs(xx,yy);
	}
}


int main()
{
	#ifdef LOCAL
	freopen("D:\\1.in","r",stdin);
	#endif
	int sta_x,sta_y;
	while(cin >> c >> r,c){
		memset(map,0,sizeof(map));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				{
					cin >> map[i][j];
					if(map[i][j] == '@')
					{
						sta_x=i;
						sta_y=j;
					}
				}
				vis[sta_x][sta_y]=1;
				//bfs遍历


			for(int i=0;i<4;i++)
			{
				int xx,yy;
				xx=sta_x+dir_x[i];
				yy=sta_y+dir_y[i];
				bfs(xx,yy);
			}
				


				int num=0;
				for(int i=1;i<=r;i++)
					for(int j=1;j<=c;j++)
					{
						if(vis[i][j]) num++;
					}
			cout << num << endl;
	}
	return 0;
}

/*
6 9
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........
11 6
..#..#..#..
..#..#..#..
..#..#..###
..#..#..#@.
..#..#..#..
..#..#..#..
7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..
0 0



*/