#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int maxn=100000;
struct QNode
{
	int N,times;
};
int N,K;
bool vis[maxn];
int can(int x)
{
	if(x < 0 || x > maxn || vis[x]) return 0;
	return 1;
}
int bfs(int k,int times)
{
	queue<QNode>Q;

	Q.push((QNode){k,times});
	while(!Q.empty())
	{
		QNode x=Q.front();Q.pop();
		int nn=x.N,ttimes=x.times;
		if(nn==K) return ttimes;
		if(can(nn-1))
			{Q.push((QNode){nn-1,ttimes+1}); vis[nn-1]=1;}
		if(can(nn+1))
		{	Q.push((QNode){nn+1,ttimes+1}); vis[nn+1]=1;}
		if(can(nn*2))
			{Q.push((QNode){2*nn,ttimes+1});vis[nn*2]=1;}

	}
}



int main()
{
	while(cin >> N >> K)
	{
			memset(vis,0,sizeof(vis));
			int times=bfs(N,0);
			cout << times << endl;
	}
	return 0;
}
