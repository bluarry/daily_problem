/*
dp(i,k)代表一个长度为k的数据，存着前k大的元素。
            ps: 个人理解为，dp[i][j][k]代表i个物品，容量为j时 的第k大的价值。
那么dp(i,V)=topK{dp(i-1,v) merge (dp(i-1,v-v[i])+value[i])}.

实际做的时候，在遍历背包的内层循环时，对整个ksize数组操作，两个数组合并，去重排序即可。
这里由于要去重所以不能直接用nth_element，直接用了sort+unique，（unique结束别忘记处理后边的无效元素为0）。

其实插排的时候顺便去重比较好。
*/

#include <string.h>
#include <string>
#include <stdio.h> 
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

int T,N,V,K;
int value[1008];
int volume[1008];

int main()
{    
    freopen("in.txt","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        int dp[1008][38]={0};
        scanf("%d %d %d",&N,&V,&K);
        for(int i = 0;i < N;++i)
            scanf("%d",value+i);
        for(int i = 0;i < N;++i)
            scanf("%d",volume+i);
        
        for(int i = 0;i < N;++i)
        {
            for(int j = V;j >= volume[i];--j)
            {
                int a[70]={0};
                int cnt = 0;
                for(int k = 0;k < K;++k)
                {
                    a[cnt++] = dp[j][k];
                    a[cnt++] = dp[j-volume[i]][k]+value[i];
                }
                
                sort(a,a+cnt,greater<int>());//不能直接用nth_element，因为要去重
                int* cnt2 = unique(a,a+cnt) ;
                while(cnt2 != a+cnt)//去完重，其余的值为0 
                {
                    *cnt2 = 0;
                    ++cnt2;
                }                
                copy(a,a+K,dp[j]);
            }
        }
        printf("%d\n", dp[V][K-1]);
    }
}