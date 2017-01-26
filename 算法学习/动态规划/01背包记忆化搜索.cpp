#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn=2000+5;
int N,W;
int w[maxn],v[maxn];
int dp[maxn][maxn];

int rec(int i,int j)
{
    if(dp[i][j]>0)
        return dp[i][j];
    int res;
    if(i==N)
    {
        res=0;
    }
    else if(j<w[i])
    {
        res=rec(i+1,j);
    }
    else{
        res=max(rec(i+1,j),rec(i+1,j-w[i])+v[i]);
    }

    return dp[i][j]=res;
}



int main()
{
    freopen("./in","r",stdin);
    cin >> N >> W;
    for(int i=0;i<N;i++)
    {
        cin >> w[i] >> v[i];
    }
    memset(dp,-1,sizeof(dp));
    cout << rec(0,W) << endl;
    return 0;
}
