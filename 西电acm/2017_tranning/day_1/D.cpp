#include <bits/stdc++.h>
using namespace std;
const int maxn=(int )1e6+5;
bitset<1000> B[15],D;
char s[5*maxn];
int n,m,k;
//Shift-And算法
int main()
{
    // freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m);
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&k);
            B[k].set(i);
        }
    }
    getchar();
    gets(s);
    int len=strlen(s);
    for(int i=0;i<len;i++){
        D<<=1;
        D|=1;
        D&=B[s[i]-'0'];
        if(D[n-1]==1)
        {
            //每当D的最高位为1时，即已经得到答案
            char ch=s[i+1];
            s[i+1]=0;
            puts(s+i-n+1);
            s[i+1]=ch;
        }
    }
    return 0;
}
