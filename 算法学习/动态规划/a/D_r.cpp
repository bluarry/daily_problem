#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

double p0,p[105];
int n,v[105];
double dp[10000+5];

int main()
{
	//freopen("in.txt","r",stdin);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> p0 >> n;
		int sum=0;	//背包容量
		for(int i=1;i<=n;i++)
		{
			cin >> v[i] >> p[i];
			sum+=v[i];
		}
		memset(dp,0,sizeof(dp));

		dp[0]=1;	//初始条件 
		for(int i=1;i<=n;i++)
			for(int j=sum;j>=v[i];j--)
			{
				dp[j]=max(dp[j],dp[j-v[i]]*(1-p[i]));
			}
			
		for(int i=sum;i>=0;i--)
		{
			if(dp[i] > (1-p0))
			{
				cout << i <<endl;
				break;
			}
		}
			

	}
	return 0;
}
