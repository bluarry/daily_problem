#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAX 1000+5
#define INF 0x7fffffff
int dp[MAX][MAX];
int n,k;
int main()
{
	while(cin >> n >> k)
	{
		int temp=long (floor(log(k+0.0)/log(2.0))+1.0);//计算二分所用最大的次数
		if(n >= temp) cout << temp <<endl;		//如果蛋数大于二分所用的次数，就输出二分次数
		else	//蛋的数目小于二分的次数
		{
			for(int i=0;i<MAX;i++) for(int j=0;j<MAX;j++) dp[i][j]=MAX;
			for(int i=1;i<MAX;i++)dp[1][i]=1;		//初始化dp数组为1 
			for(int i=1;i<MAX;i++)dp[i][1]=i;
			if(k==0 || k==1) cout <<1 << endl;	//k==0 || k==1 的时候,即楼层数为1或0时
			else if(n==1) cout << k <<endl;		//n==1,即只有一个蛋,那么只能从一层往上一层一层试，最坏的情况下为k
			else{
					for(int i=2;i<=k;i++)
					{
						for(int j=2;j<=n;j++)
						{
							dp[i][j]=dp[i-1][j-1]+dp[i-1][j]+1;
							if((j==n)&& (dp[i][j]>=k))
							{
								cout << i <<endl;
								 goto tag;
							}
						}
					}
					 tag:;
				}
		}
	}
	return 0;
}
