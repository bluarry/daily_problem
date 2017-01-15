#include <iostream>
using namespace std;
const int maxn=105;
int N,M;
char filed[maxn][maxn];
void dfs(int i,int j)
{
	filed[i][j]='.';
	for(int x=-1;x<=1;x++)
		for(int y=-1;y<=1;y++)
		{
			int xx=i+x,yy=j+y;
			if(xx>=0 && xx<N && yy>=0 && yy <M && filed[xx][yy]=='W' )
			{
				dfs(xx,yy);
			}
		}
}		
int solve()
{
	int co=0;

for(int i=0;i<N;i++)
	for(int j=0;j<M;j++)
		if(filed[i][j]=='W')
		{
			dfs(i,j);
			co++;
		}
		return co;
}
int main()
{
	cin >> N >> M;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin >> filed[i][j];
	cout << solve() << endl;

	return 0;
}