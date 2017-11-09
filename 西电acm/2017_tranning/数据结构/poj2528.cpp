#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define lson (pos<<1)
#define rson ((pos<<1)|1)
const int maxn=10000+5;
int n;
int li[maxn],ri[maxn];
int lisan[maxn*4],tree[maxn*16];
bool vis[maxn*4];
void pushdown(int pos)
{
    tree[lson]=tree[rson]=tree[pos];
    tree[pos]=-1;
}
void update(int p,int l,int r,int x,int y,int v)
{
    if(x<=l&&y>=r)
    {
        tree[p]=v;
        return;
    }
    if(tree[p]!=-1) pushdown(p);
    int mid=(l+r)>>1;
    if(y<=mid) update(p<<1,l,mid,x,y,v);
    else if(x>mid) update((p<<1)|1,mid+1,r,x,y,v);
    else update(p<<1,l,mid,x,mid,v),update((p<<1)|1,mid+1,r,mid+1,y,v);
}
void Modify(int L,int R,int l ,int r ,int a,int pos)
{
    if(l<=L && r>=R ){
            // cout << L<< ' ' << R << endl;
        tree[pos]=a;
        return;
    }
    // cout << l<< ' ' << r <<' '<< L<< ' ' << R << endl;
    if(tree[pos]!=-1) pushdown(pos);
    int mid=(L+R)/2;
    if(r<=mid) Modify(L,mid,l,r,a,lson);
    else if(l>mid) Modify(mid+1,R,l,r,a,rson);
    else {
        Modify(L,mid,l,mid,a,lson);
        Modify(mid+1,R,mid+1,r,a,rson);
    }
}
int ans;
void Query(int l,int r,int pos)
{
        if((tree[pos]!=-1)){
            if(!vis[tree[pos]])
            {
                ans++;
                vis[tree[pos]]=true;
            }
            return;
        }

        if(l==r) return;
        // if(tree[pos]!=-1) pushdown(pos);
        int mid=(l+r)/2;

        Query(l,mid,lson);
        Query(mid+1,r,rson);
}

int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int m=0;
        memset(vis,false,sizeof vis);
        memset(tree,-1,sizeof tree);
        for(int i=0;i<n;i++)
        {
            cin >> li[i]>> ri[i];
            lisan[m++]=li[i];
            lisan[m++]=ri[i];
        }
        sort(lisan,lisan+m);

        int x=unique(lisan,lisan+m)-lisan;
        int y=x;
        // for(int i=1;i<x;i++) cout << lisan[i] << " ";cout << endl;

        for(int i=1;i<y;i++)
        {
            if(lisan[i]-lisan[i-1]>1)
                lisan[++x]=lisan[i-1]+1;
        }
         sort(lisan,lisan+x);

        // for(int i=1;i<x;i++) cout << lisan[i] << " ";cout << endl;

        for(int i=0;i<n;i++){
            int l=lower_bound(lisan,lisan+x,li[i])-lisan;
            int r=lower_bound(lisan,lisan+x,ri[i])-lisan;
            // cout << "Modify : " << l << ' '<< r << endl;
            Modify(0,x-1,l,r,i,1);
        }
        ans=0;
        Query(1,x,1);
        cout << ans << endl;
    }
    return 0;
}
