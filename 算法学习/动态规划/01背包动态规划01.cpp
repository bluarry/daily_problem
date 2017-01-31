#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=100;
int N,W;
int v[maxn],w[maxn];
int dp[maxn][maxn];
int main()
{
    cin >> N>>W;
    for(int i=0;i<N;i++)
    cin >> w[i]>>v[i];
    
    for(int i=N-1;i>=0;i--)
    for(int j=0;j<=W;j++)
    {
        if(j<w[i])
        {
            dp[i][j]=dp[i+1][j];
        }
        else
            dp[i][j]=max(dp[i+1][j],dp[i+1][j-w[i]]+v[i]);
    }

    for(int i=0;i<N ;i++)
    for(int j=0;j<=W;j++)
    j==W?cout << dp[i][j]<<endl:cout << dp[i][j] << "  ";

    cout << dp[0][W] << endl;

    return 0;
}
/*
2 2
4 5
2 3
1 2
3 4
*/
