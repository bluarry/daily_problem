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

    
        for(int i=0;i<n;i++)
        {
            *lower_bound(dp,dp+n,a[i])=a[i];
        }
    
    
    cout << lower_bound(dp,dp+n,INF)-dp << endl;

    return 0;
}

