#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=1000+5;
const int maxm=10000+5;

int M,n,m;

int dp[maxm][maxn];


int main()
{
    cin >> m >> n >> M;
   dp[0][0]=1; 
    for(int i=1;i<=m;i++)
        for(int j=0;j<=n;j++)
    {
            if(j-i>=0)
        {
            dp[i][j]= (dp[i][j-i]+dp[i-1][j])%M;
        }
        else
            dp[i][j]=dp[i-1][j];
    }
    
    cout << dp[m][n] <<endl;

    return 0;
}
