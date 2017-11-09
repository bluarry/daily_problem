#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
bitset<1000>b[20],ans;
int n,m,k;
char s[5*maxn];
//shift-and算法
int main()
{
    // freopen("in.txt","r",stdin);
    scanf("%d",&n);
    //Shift-And算法获取 B
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m);
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&k);
            b[k].set(i);
        }
    }
    getchar();
    gets(s);
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        ans<<=1;
        ans[0]=1;
        ans &=b[s[i]-'0'];
        if(ans[n-1]==1)
        {
            char ch=s[i+1];
            s[i+1]=0;
            puts(s+i-n+1);
            s[i+1]=ch;
        }
    }
    return 0;
}
