#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=16;
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
		if(xx < 0 || xx >=N || yy<0 || yy>=M) continue;
		G_t[xx][yy]=!G_t[xx][yy];
	}
}
bool isZero(int n)
{
		for(int i=0;i<M;i++)
				if(G_t[n][i]) return false;
	return true;
}


void solve(int num){
		memcpy(G_t,G,sizeof(G));
		memset(tmp,0,sizeof(tmp));
		int cnt=0;

		for(int i=0;i<M;i++)
				if((num>>i) & 1)
				{
						filp(0,i);
						cnt++;
				}
		for(int i=1;i<N;i++)
				for(int j=0;j<M;j++)
					if(G_t[i-1][j]==1){
					filp(i,j);
					cnt++;
					}
		if(isZero(N-1) && cnt < ans)
		{
			ans=cnt;
			memcpy(res,tmp,sizeof(tmp));
		}
}



int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(cin >> N >> M){		//题目中是M行，N列，没什么影响
	
			for(int i=0;i<N;i++)
				for(int j=0;j<M;j++)
				{
					cin >> G[i][j];
				}
		ans=INF;
		for(int i=0;i<(1<<M);i++)
			solve(i);
		
		if(ans==INF)
		{
				puts("IMPOSIBLE");
		}else{
				for(int i=0;i<N;i++)
				{
					for(int j=0;j<M;j++)
					{
						j==M-1?cout << res[i][j]<<endl:cout << res[i][j]<<" ";

					}
				}
			}

	
	}	
	return 0;
}
