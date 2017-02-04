#include <iostream>
#include <algorithm>
//#define 99999999 INF;
//#define INF  99999999;
using namespace std;
 const int maxn=100;
 const int maxv=100;
int n,W;
int w[maxn],v[maxv];
int dp[maxn+1][maxn*maxv+1];

int main()
{
    cin >> n >> W;

    for(int i=0;i<n;i++)
    cin >> w[i]>>v[i];
    
    fill(dp[0],dp[0]+maxn*maxv+1,99999999 );
    dp[0][0]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<maxn*maxv;j++)
    {
        if(j<v[i])
        dp[i+1][j]=dp[i][j];
        else
        dp[i+1][j]=min(dp[i][j],dp[i][j-v[i]]+w[i]);
    }
    
    int res=0;
    
        for(int j=0;j<maxn*maxv;j++)
                        if(dp[n][j]<=W) res=j;

    cout << res<<endl;
   return 0;
}
