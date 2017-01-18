#include <iostream>
#include <queue>
using namespace std;
const int maxn=105;
const int INF=1e8;
int N,M;
int sx,sy,gx,gy;
char G[maxn][maxn];
int B[maxn][maxn];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
typedef pair<int,int> P;
int bfs()
{
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		{
			B[i][j]=INF;
		}

		queue<P> q;
		q.push(P(sx,sy));
		B[sx][sy]=0;
		while(!q.empty())
		{
			P p=q.front();q.pop();
			if(p.first==gx && p.second == gy) break;

			for(int i=0;i<4;i++)
			{
				int ddx=dx[i]+p.first;
				int ddy=dy[i]+p.second;
				
				if(ddx>=0 && ddx < N && ddy >=0 && ddy <M && G[ddx][ddy]!='#' && B[ddx][ddy] == INF)
				{
					q.push(P(ddx,ddy));
					B[ddx][ddy]=B[p.first][p.second] + 1;
				}

			}
		}


		return B[gx][gy];
}

int main()
{
	cin >> N >> M;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			{
				cin >> G[i][j];
				if(G[i][j] == 'S') sx=i,sy=j;
				if(G[i][j] == 'G')	gx=i,gy=j;
			}
	cout << bfs() << endl;
	return 0;
}

/*
10 10
#S######.#
......#..#
.#.##.##.#
.#........
##.##.####
....#....#
.#######.#
....#.....
.####.###.
....#...G#
*/
