#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX=1000+5;
/*
dp[i][j][k]代表第i个物品剩余j容量空间的第k大的价值
由于i可以省略，故只用二维
dp[j][k]即可
初始化为0
*/
int main()
{
	//freopen("in.txt","r",stdin);
	int T;
	cin >> T;
	while(T--)
	{
		
		int v[MAX]={0},w[MAX]={0},dp[MAX][35]={0};			
		int N,V,K;
		cin >> N >> V >> K;
		for(int i=1;i<=N;i++) cin >> v[i];
		for(int i=1;i<=N;i++) cin >> w[i];

		for(int i=1;i<=N;i++)
			for(int j=V;j>=w[i];j--)
				{	
					std::vector<int> ve;
					ve.clear();
					for(int k=0;k<K;k++)
					{
						ve.push_back(dp[j][k]);
						ve.push_back(dp[j-w[i]][k]+v[i]);
					}

					//此时得到的序列非最大排列，需要先排序，在去重即可
					sort(ve.begin(),ve.end(),greater<int>());
					
					 vector<int>::iterator  cnt2 =unique(ve.begin(), ve.end());
					 while(cnt2 != ve.end())//去完重，其余的值为0 
				        {
				            *cnt2 = 0;
				            ++cnt2;
				        }               
					for(int xx=0;xx<K;xx++)
						dp[j][xx]=ve[xx];
				}


		cout << dp[V][K-1] <<endl;
	}
	return 0;
}
