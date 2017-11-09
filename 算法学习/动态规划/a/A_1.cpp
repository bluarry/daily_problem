#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,w[1005],m,M;

int dp[1005];


int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out2.txt","w+",stdout);
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
		{
			// for(int x=1;x<M;x++) cout << dp[x] << " ";
			// 	cout << endl;
			for(int j=M;j>=w[i];j--)
			{
				dp[j]=max(dp[j],dp[j-w[i]]+w[i]);
			}
		}
		cout << m-dp[M]-w[n] <<endl;
	}		
	return 0;
}
