/*
 * lcs问题是求两个字符串的最长公共子序列,子序列不必要连续;
 *动态转移方程为:
 *dp[i][j]表示序列长分别为i和j的最长公共子序列
 *              =max(dp[i][j]+1,dp[i+1][j],dp[i][j+1]) s[i]==t[i];
 * dp[i+1][j+1]=
 *              =max(dp[i+1][j],dp[i][j+1]);
 *
 *
 * / 
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    string s,t;
    
    cin >> s; 
    cin >> t;
    
    s="#"+s;
    t="#"+t;
    int dp[100][100]={0};
    
    for(int i=1;i<=s.length();i++)
        for(int j=1;j<=t.length();j++)
        {
         if(s[i]==t[j])
            dp[i+1][j+1]=max(dp[i][j]+1,max(dp[i+1][j],dp[i][j+1]));
        else
            dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
        }

    cout << dp[s.length()][t.length()] << endl; 
    return 0;
}
