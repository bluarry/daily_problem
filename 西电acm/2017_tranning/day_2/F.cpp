#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=4000+5;
int w[25],N,dp[maxn];
int main()
{
	// freopen("in.txt","r",stdin);
	int _;
	cin >> _;
	while(_--){
		cin >> N;
		for(int i=1;i<=N;i++) cin >> w[i];

		/*
		一。用背包来解决的话，首先要想dp方程，首先想在天平上只在一边放的情况。
			1.设dp[i][j]代表前i件物品是否可以称量重量为j的物品;
			dp方程可写为 dp[i][j]=dp[i-1][j]|dp[i-1][j-a[i]] 表示前i件物品是否可以称量重量为j的物品可由 
				1). 前i-1件物品是否可以称量重量为j的物品; 
				2).前i-1件物品是否可以称量重量为j-a[i]的物品，如果可以的话，再加入a[i]即可称重.
			以上两个状态转移得到，那么当前的dp[i][j]即可满足 。
			2. 第1步只完成了只在天平一边放物品时的可称量重量，需要继续做转移到两边都放
				dp[i][j] 代表同上
				1). 前i-1件物品是否可以称量重量为j的物品; 
				2).前i-1件物品是否可以称量重量为j+a[i]的物品，如果可以的话，再减去a[i]即可称重.
				那么，通过上述的转移可将两边都能称量的情况考虑到.
		*/
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=1;i<=N;i++)
			for(int j=2005;j>=w[i];j--)
				dp[j]|=dp[j-w[i]];
		for(int i=1;i<=N;i++)
			for(int j=1;j<2005;j++)
				dp[j]|=dp[j+w[i]];
		int x;
		cin >> x;
		while(x--)
		{
			int p;
			cin >> p;
			if(p <= 2000 && dp[p]) cout << "YES"<<endl;
			else cout << "NO"<<endl;
		}


	}
	return 0;
}
