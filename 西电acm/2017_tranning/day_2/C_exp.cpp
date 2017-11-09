#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
const long long INF = 0x7fffffffffffffffll;
using namespace std;
long long ans;
long long n;
bool work(long long x)
{
    if(x<2)
        return false;
    long long t=x;
    for(long long i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            if(x%(i*i)==0)//出现了超过一次
            {
                return false;
            }
            x/=i;
        }
    }
    ans=min(ans,abs(t*t-n));
    return true;
}
int main (void)
{
	freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%I64d",&n);
        long long x=(long long)(sqrt(n)+0.5);
        int flag=0;
        ans=INF;
        for(int i=0;;i++)
        {
            if(work(x+i))
                flag=1;
            if(work(x-i))
                flag=1;
            if(flag==1)
                break;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
