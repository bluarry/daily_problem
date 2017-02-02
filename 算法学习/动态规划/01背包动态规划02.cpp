#include <iostream>
using namespace std;
const int maxn=100;
int v[100],w[100];
int n,W;
int dp[maxn][maxn];
int main()
{
    cin >> n >> W;

    for(int i=0;i<n;i++)
    {
        cin >> w[i] >> v[i];
    }
    
    for(int i=0;i<n;i++)
    for(int j=0;j<=W;j++)
    {
        if(j<w[i])
        {
            dp[i+1][j]=dp[i][j];
        }
        else 
        {
            dp[i+1][j]=max(dp[i][j],dp[i][j-w[i]]+v[i]);
        }
    }
    
    cout << dp[n][W]<<endl;





    return 0;
}
