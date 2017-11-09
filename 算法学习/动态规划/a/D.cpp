#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int v[100+5],w[100+5];
int dp[100+5];
int main()
{
//	freopen("in.txt","r",stdin);
	int T;
	cin >> T;
	while(T--){
		double PP;
		int n;
		cin >> PP >> n;
		int P=int(float(PP*100));
		for(int i=1;i<=n;i++)
		{
			cin >> v[i];
			double x;
			cin >> x;
			//cout << x*1000<<endl;
			w[i]=(int)(float(x*100));
			//cout <<v[i] <<" "<< w[i] <<endl;
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			for(int j=P;j>=w[i];j--)
			{
				dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
			}	
		}
		cout << dp[P] << endl;
	}
	return 0;
}
