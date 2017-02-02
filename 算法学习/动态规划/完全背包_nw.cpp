#include <iostream>
#include <algorithm>
using namespace std;

const int maxn=100;
int N,W;
int w[maxn],v[maxn];
int dp[maxn][maxn];



int main()
{
    cin >> N >> W;
    
    for(int i=0;i<N;i++)
    cin >> w[i]>> v[i];
    
    for(int i=0;i<N;i++)
        for(int j=0;j<=W;j++)
        {
            if(j<w[i])
            dp[i+1][j]=dp[i][j];
            else 
            dp[i+1][j]=max(dp[i][j],dp[i+1][j-w[i]]+v[i]);
        }
    
    cout << dp[N][W] << endl;
    return 0;
}
