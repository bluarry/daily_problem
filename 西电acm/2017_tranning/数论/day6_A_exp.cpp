#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9;
const double eps = 1e-6;
const int N = 1000010;
int cas = 1;

struct _node{
    int x,y,k;
    void set(int _k, int _x, int _y)
    {
        k = _k;
        x = _x;
        y = _y;
    }
};
_node point[N];
int xk[N],cnt[N];
int n,m,dx,dy;

void run()
{
    point[0].set(0,0,0);
    xk[0] = 0;
    for(int i=1; i<n; i++)
    {
        point[i].set(i,(point[i-1].x+dx)%n,(point[i-1].y+dy)%n);
        xk[point[i].x] = i;
    }
    memset(cnt,0,sizeof(cnt));
    int x,y,k,y0,yk;
    while(m--)
    {
        scanf("%d%d",&x,&y);
        k = xk[x];
        yk = point[k].y;
        y0 = (y - yk + n) % n;
        cnt[y0]++;
    }
    int mx=cnt[0], pos=0;
    for(int i=1;i<n;i++)
        if(mx < cnt[i])
            mx=cnt[i], pos=i;
    printf("0 %d\n",pos);
}

int main()
{
    #ifdef LOCAL
    freopen("case.txt","r",stdin);
    #endif
    while(scanf("%d%d%d%d",&n,&m,&dx,&dy)!=EOF)
        run();
    return 0;
}