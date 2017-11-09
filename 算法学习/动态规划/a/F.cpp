#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int N,M;
typedef struct {
	int  P,Q,V;
}Node;
Node X[500+5];
int dp[5000+5];
bool cmp(Node a,Node b)
{
	return (a.Q-a.P)< (b.Q-b.P);
}
int main()
{
//	freopen("in.txt","r",stdin);
	while(cin >> N >> M)
	{
		for(int i=1;i<=N;i++)
			cin >> X[i].P >> X[i].Q >> X[i].V;
		sort(X+1,X+N,cmp);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=N;i++)
			for(int j=M;j >= X[i].Q ;j--)
			{
					dp[j]=max(dp[j],dp[j-X[i].P]+X[i].V);
			}

		cout << dp[M] << endl;

	}
	return 0;
}
