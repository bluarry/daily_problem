#include <iostream>
#include <algorithm>

using namespace std;
const int maxN=100+5;
int a[maxN],m[maxN];// a值
bool dp[maxN+1][maxN+1];
int n,k;

int main()
{
    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
    cin >> m[i];

    dp[0][0]=true;
    for(int i=0;i<n;i++)
        for(int j=0;j<=k;j++)
            for(int q=0;q<=m[i] &&q*a[i]<=j;q++)
                dp[i+1][j] |= dp[i][j-q*a[i]];


    for(int i=0;i<=n;i++)
        for(int j=0;j<=k;j++)
    j==k?cout << dp[i][j]<<endl:cout << dp[i][j]<< " ";   

    if(dp[n][k])cout << "Yes"<<endl;
    else
    cout << "No"<<endl;
    return 0;
}
