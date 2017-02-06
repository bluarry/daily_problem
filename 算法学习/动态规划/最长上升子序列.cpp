#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1000;
int n;
int a[maxn];

int dp[maxn];
int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    
    int res=0;
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        res=max(res,dp[i]);
    }

    cout << res<<endl;


    return 0;
}
