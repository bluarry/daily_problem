#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define lson(x) (2*x)
#define rson(x) (2*x+1)
#define QuickIO() {cin.tie(0);ios::sync_with_stdio(false);cout.tie(0);}
const ll maxn=1e5+5;

struct Treenode{
    ll l,r,sum;
};
Treenode tree[maxn*4+5];
ll lazy[maxn*4+5];
void build(ll l,ll r,ll pos){ //建立线段树
    if(l==r){
        tree[pos].l=tree[pos].r=l;
        cin >> tree[pos].sum;
        return;
    }
    ll mid=(l+r)/2;
    build(l,mid,lson(pos));
    build(mid+1,r,rson(pos));
    tree[pos].l=l;tree[pos].r=r;
    tree[pos].sum=tree[lson(pos)].sum+tree[rson(pos)].sum;
}
void pushdown(ll pos)   //将父亲的lazy传递下去给儿子节点
{
    ll l=tree[pos].l,r=tree[pos].r;
    ll mid=(l+r)/2;
    lazy[lson(pos)]+=lazy[pos];
    lazy[rson(pos)]+=lazy[pos];
    tree[lson(pos)].sum+=(mid-l+1)*lazy[pos];
    tree[rson(pos)].sum+=(r-mid)*lazy[pos];
    lazy[pos]=0;
}
ll Querry(ll l,ll r,ll pos){    //查询区间[l,r]之间的和
    if(l==tree[pos].l && r == tree[pos].r){
        return tree[pos].sum;
    }
    if(lazy[pos])
        pushdown(pos);
    ll mid=(tree[pos].l+tree[pos].r)/2;
    if(r<=mid) return Querry(l,r,lson(pos));
    if(l>mid)  return Querry(l,r,rson(pos));

    return Querry(l,mid,lson(pos))+Querry(mid+1,r,rson(pos));
}

//修改,由于是区间修改，那么就只维护lazy
void Modify(ll l,ll r,ll x,ll pos){
    if(tree[pos].l==l && tree[pos].r==r){
            tree[pos].sum+=x*(r-l+1);
            lazy[pos]+=x;
        return ;
    }
    if(tree[pos].l==tree[pos].r) return ;       //这条优化不加会T掉
    if(lazy[pos]){
        pushdown(pos);
    }
    ll mid=(tree[pos].l+tree[pos].r)/2;
    if(r<=mid) Modify(l,r,x,lson(pos));
    else if(l>mid) Modify(l,r,x,rson(pos));
    else
    {
        Modify(l,mid,x,lson(pos));
        Modify(mid+1,r,x,rson(pos));
    }
    tree[pos].sum=tree[lson(pos)].sum+tree[rson(pos)].sum;
}

ll N,Q;
int main()
{
	QuickIO();
    // freopen("in.txt","r",stdin);
    while(cin >> N >> Q){
        memset(lazy,0,sizeof lazy);
        build(1,N,1);
        char c;
        ll x,y,z;
        while(Q--){
            cin >> c;
            if(c=='Q')
            {
                cin >> x >> y;
                cout << Querry(x,y,1) << endl;
            }
            else if(c=='C'){
                cin >> x >> y >> z;
                Modify(x,y,z,1);
            }

        }
    }
    return 0;
}
