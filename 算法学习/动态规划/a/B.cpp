#include <iostream>
#include <cstdio>
using namespace std;
const int MAX=1000+5;

int main()
{
	//freopen("in.txt","r",stdin);
	int T;
	cin >> T;
	while(T--)
	{
		int v[MAX]={0},w[MAX]={0},dp[MAX]={0};
		int N,V;
		cin >> N >> V;
		for(int i=1;i<=N;i++) cin >> v[i];
		for(int i=1;i<=N;i++) cin >> w[i];

		for(int i=1;i<=N;i++)
			for(int j=V;j>=w[i];j--)
					dp[j]=max(dp[j],dp[j-w[i]]+v[i]);

		cout << dp[V] <<endl;

	}
	return 0;
}
