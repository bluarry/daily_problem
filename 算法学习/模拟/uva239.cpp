#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
typedef long long ll;

const int maxn=7000+5;

int lim[]={4,11,12};//之所以是12  是因为最后小时的槽子满的时候,先将小时位弹出,然后是最后进入最后一位,再弹出到初始队列里

int N,pos[maxn],v[maxn];
ll gcd(ll a,ll b)
{
    return b==0? a:gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
    return a/gcd(a,b)*b;
}

void getset()
{
    queue<int> que;
    int s[3][12],c[3];

    for(int i=1;i<=N;i++)
        que.push(i);

    for(int xxx=0;xxx<2;xxx++)
    {
        c[0]=c[1]=c[2]=0;
        for(int k=0;k<12*60;k++)
        {
            int p=0;//0,1,2 分别代表的1分钟槽,5分钟槽,1小时槽
            while(1){
                if(c[p]!=lim[p])    //当前槽不满时
                {
                    s[p][c[p]++]=que.front();
                    que.pop();
                    break;
                }
                else
                {
                    while(c[p]) que.push(s[p][--c[p]]);
                    p++;
                }
            }
        }

        for(int j=10;j>=0;j--)
            que.push(s[2][j]);
        que.push(s[2][11]);
    }

    int m=1;
    while(!que.empty())
    {
        pos[m++]=que.front();
        que.pop();
    }
}


ll solve()
{
    getset();   //模拟得到pos序列

    memset(v,0,sizeof(v));


    ll ret=1;
    for(int i=1;i<=N;i++)
    {
        if(v[i]) continue;  //去掉重复的
        int x=i;
        ll cnt=0;
        while(v[x]==0)
        {
            v[x]=1;
            cnt++;
            x=pos[x];
        }
        ret=lcm(ret,cnt);
    }
    return ret;
}

int main()
{
    while(cin >> N && N)
    {
        cout << N<<" balls cycle after "<<solve() <<" days."<<endl;
    }


    return 0;
}
