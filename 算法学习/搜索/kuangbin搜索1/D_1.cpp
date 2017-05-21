//#define HEHE
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=17;
const int INF=9999999;
int N,M,ans;
int G[maxn][maxn],G_t[maxn][maxn],tmp[maxn][maxn],res[maxn][maxn];
int dir_x[]={1,-1,0,0,0};
int dir_y[]={0,0,1,-1,0};
void filp(int x,int y){
	tmp[x][y]=1;
	int xx,yy;
	for(int i=0;i<5;i++)
	{
		xx=x+dir_x[i];yy=y+dir_y[i];
		//if(xx < 0 || xx >=N || yy<0 || yy>=M) continue;
		G_t[xx][yy]=!G_t[xx][yy];
	}
}
bool isempty(int n)
{
		for(int i=1;i<=M;i++)
				if(G_t[n][i]) return false;
	return true;
}


void solve(int num){
		memcpy(G_t,G,sizeof(G));
		memset(tmp,0,sizeof(tmp));
		int cnt=0;

		for(int j=0;j<M;j++)
				if((num>>j) & 1)
				{
						filp(1,j+1);
						cnt++;
				}
		for(int i=2;i<=N;i++)
				for(int j=1;j<=M;j++)
					if(G_t[i-1][j]==1){
					filp(i,j);
					cnt++;
					}
		if(isempty(N) && cnt < ans)
		{
			ans=cnt;
			memcpy(res,tmp,sizeof(tmp));
		}
}



int main()
{
	#ifdef HEHE
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	#endif
	while(cin >> N >> M){		//题目中是M行，N列，没什么影响
	
			for(int i=1;i<=N;i++)
				for(int j=1;j<=M;j++)
				{
					cin >> G[i][j];
				}
		ans=INF;
		int end=(1<<M);
		for(int i=0;i<end;i++)
			solve(i);
		
		if(ans==INF)
		{
				puts("IMPOSIBLE");
		}else{
				for(int i=1;i<=N;i++)
				{
					for(int j=1;j<=M;j++)
					{
						j==M?cout << res[i][j]<<endl:cout << res[i][j]<<" ";

					}
				}
	
			}

	
	}	
	return 0;
}
