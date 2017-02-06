#include <iostream>
#include <algorithm>
using namespace std;
const int INF=9999999;
const int maxn=1000;
int n;
int a[maxn];

int dp[maxn];
int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    
    fill(dp,dp+n,INF);

    
    for(int j=0;j<n;j++)
    for(int i=0;i<n;i++){
        if(i==0 || dp[i-1]<a[j])
        {
            dp[i]=min(dp[i],a[j]);
        }

    }
    
    int ma=0;
    for(int i=0;i<n;i++)
        if(dp[i]!=INF)
    {
        if(dp[i]>dp[ma])
        ma=i;
    }
    
    cout << ma+1 <<endl;
    
    


    return 0;
}
