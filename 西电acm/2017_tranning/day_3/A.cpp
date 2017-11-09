#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
double q;
int N;
/*
思路：首先钱数为double型，那么背包就为发票，价值即为报销的钱数
dp[j]代表前j个物品报销的钱数，dp[j]=max(dp[j],dp[j-1]+v[i])
*/
double dp[40];	//
double v[40];
int main()
{
//	freopen("in.txt","r",stdin);
	while(~scanf("%lf%d",&q,&N),N)
	{
		int cnt=1;			//将价格的浮点数整数化
		memset(dp,0,sizeof(dp));
		memset(v,0,sizeof(v));
		while(N--)
		{
			double A,B ,C;
			int k=0,flag=1;
			scanf("%d",&k);
			A=B=C=0;
			for(int i=0;i<k;i++)
			{
				char ch;
				double x;
				scanf(" %c:%lf",&ch,&x);

				if(ch=='A') A+=x;
				else if(ch=='B') B+=x;
				else if(ch=='C') C+=x;
				else flag=0;
			}
			if(A+B+C <= 1000 && A <=600 && B<=600 && C <=600 && flag )
			{
				v[cnt++]=A+B+C;
			}
		}
		// for(int i=1;i<=cnt;i++)
		// 	printf("%.2lf ",v[i] );
		// putchar('\n');
		for(int i=1;i<=cnt;i++)
			for(int j=cnt; j>=2;j--)
				if( j==2 || dp[j-1] > 0 && dp[j-1]+v[i] <= q )
					dp[j]=max(dp[j],dp[j-1]+v[i]);

		int x=0;
		for(int i=1;i<=cnt;i++)
			if(dp[i]>dp[x])
				x=i;

		printf("%.2lf\n", dp[x]);
	}

	return 0;
}
