#include <iostream>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;
LL dp[105][105][105];
int main(int argc, const char * argv[])
{
    LL n,x,y,z,t;
    while (cin >> n >> x >> y >> z >> t)
    {
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)//y
            {
                for(int k=0;k+j<i;k++)//z
                {
                    //放置红色塔
                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+(LL)(t+k*z)*(x+j*y));
                    //放置绿色塔
                    dp[i][j+1][k]=max(dp[i][j+1][k],dp[i-1][j][k]+(LL)(t+k*z)*(j*y));
                    //放置蓝色塔
                    dp[i][j][k+1]=max(dp[i][j][k+1],dp[i-1][j][k]+(LL)(t+k*z)*(j*y));
                }
            }
        }
        LL ans=0;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                ans=max(ans, dp[n][i][j]);
        cout << ans << endl;
    }
    return 0;
}
