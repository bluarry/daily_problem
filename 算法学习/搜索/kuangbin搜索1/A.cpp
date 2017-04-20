#define hehe
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=8;
int n,k;
int i_map[8][8];
int c[8];
int tot,used;

void dfs(int cur)
{
	if(used==k) {tot++;return;}
	if(cur>=n) { return;}
	else for(int i=0;i<n;i++)
		if(i_map[cur][i])
		{
			if(c[i]) continue;
			else
			{
				c[i]=1;
				used++;
				dfs(cur+1);
				c[i]=0;
				used--;
			}
		}
	dfs(cur+1);
}

int main()
{
	#ifdef hehe
	freopen("in.txt","r",stdin);
	#endif
	while(cin >> n >> k)
	{
		if(n==-1) break;
		
		memset(i_map,0,sizeof(i_map)); 
		tot=0;used=0;
		memset(c,0,sizeof(c));
		
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				char c;
				cin >> c;
				if(c=='#')i_map[i][j]=1;
			}

			dfs(0);
				cout << tot <<endl;




	}



	return 0;
}
