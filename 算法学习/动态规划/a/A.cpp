#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,w[1005],m,M;

int dp[1005][1005];


int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w+",stdout);
	while(cin >> n,n)
	{
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			cin >> w[i];
		sort(w+1,w+n+1);  
		
		cin >> m;
		if(m < 5){ 
			cout << m <<endl;
			continue;
		}
		M=m-5;

		for(int i=1;i<=n-1;i++)
			for(int j=1;j<=M;j++)
				if(j>= w[i])
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+w[i]);
				else 		//这里不可忽略，代表着容量不足的时候
					dp[i][j]=dp[i-1][j];

			for(int i=1;i<=n-1;i++){
			for(int j=1;j<=M;j++)
			{
				cout << dp[i][j] << " "; 
			}
			cout << endl;
		}

		cout << m-dp[n-1][M]-w[n] <<endl;
	}		
	return 0;
}
