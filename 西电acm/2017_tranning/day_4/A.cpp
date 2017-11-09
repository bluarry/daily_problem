#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=1e6+5;
int n;
double ans=0;
bool vis[maxn];
std::vector<int> e[maxn];
void dfs(int x,double p){
	vis[x]=true;
	

	int m=e[x].size(),M;
	M=m;
	if(x!=1)m--;
	if(m==0) return ;


	double xx=p*(1.0/m);
	// printf("%.3lf\n",xx );
	for(int i=0;i<M;i++)
		if(! vis[e[x][i]]){
			ans+=xx;
			dfs(e[x][i],xx);
		}

	return;
}

int main()
{
	scanf("%d",&n);
	int u,v;
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	memset(vis,false,sizeof vis);
	dfs(1,1.0);
	printf("%.15lf\n", ans);
	return 0;
}
