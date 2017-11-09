#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 1000+5
#define INF 0x7fffffff
int dp[MAX][MAX];
int n,k;


int main()
{
	for(int i=0;i<MAX;i++) for(int j=0;j<MAX;j++) dp[i][j]=INF;
	for(int i=0;i<MAX;i++) dp[i][0]=0;
	for(int j=1;j<MAX;j++) dp[1][j]=j;
	
	for(int i=2;i<=100;i++)
		for(int j=1;j<MAX;j++)
			for(int w=1;w<=j;w++)
				dp[i][j]=min(max(dp[i-1][w-1],dp[i][j-w])+1,dp[i][j]);

	while(cin >> n >> k)
	{
			cout << dp[n][k] <<endl;
	}
	return 0;
}
