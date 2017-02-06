#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=100;
const int maxk=100000;

int n,K;
int a[maxn];//值
int m[maxn];//个数
int dp[maxk+1];




int main()
{
 cin >> n >> K;
    for(int i=0;i<n;i++)
    cin >> a[i]>>m[i];
    memset(dp,-1,sizeof(dp));
    dp[0]=0;

    for(int i=0;i<n;i++)
    for(int j=0;j<=K;j++){
        if(dp[j]>=0)
        dp[j]=m[i];
        else if(j<a[i] || dp[j-a[i]]<=0){
            dp[j]=-1;
        }
        else {
            dp[j]=dp[j-a[i]]-1;
        }
    }
    
    if(dp[K] >=0) cout << "Yes"<<endl;
    else cout << "No"<< endl;
    
    
    return 0;
}
