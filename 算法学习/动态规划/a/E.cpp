#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
double q;
int N;
/*
思路：首先筛选出所有能报销的发票，然后就是01背包问题
从k张发票里选出报销额最大，但是不超过报销额度Q；
*/
int dp[3000000+5];
int v[40];
int main()
{
	freopen("in.txt","r",stdin);
	while(~scanf("%lf%d",&q,&N),N)
	{
		int Q=int(q*100),cnt=1;			//将价格的浮点数整数化
		memset(dp,0,sizeof(dp));
		memset(v,0,sizeof(v));
		while(N--)
		{
			int A,B ,C,k=0,flag=1;
			scanf("%d",&k);
			A=B=C=0;
			for(int i=0;i<k;i++)
			{
				char ch;
				double x;
				int xx;
				scanf(" %c:%lf",&ch,&x);
				xx=int(x*100);

				if(ch=='A') A+=xx;
				else if(ch=='B') B+=xx;
				else if(ch=='C') C+=xx;
				else flag=0;
			}
			if(A+B+C <= 100000 && A <=60000 && B<=60000 && C <=60000 && flag )
			{
				v[cnt++]=A+B+C;
			}
		}

		// for(int i=0;i<cnt;i++)
		// 	printf("%d ",v[i]);
		// puts("");

		for(int i=1;i<=cnt;i++)
			for(int j=Q;j>=v[i];j--)
				dp[j]=max(dp[j],dp[j-v[i]]+v[i]);

		printf("%.2lf\n", dp[Q]/100.0);
	}






	return 0;
}
