#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define lson(x) (2*x)
#define rson(x) (2*x+1)
const int maxn=50000;
//单点修改区间查询，可用线段树解决，也可用树状数组解决
int a[maxn+5];
struct Treenode{
    int l,r,sum;
};
Treenode tree[maxn*4+5];
void build(int l,int r,int pos) {   //建立线段树
    if(l==r) {
        tree[pos].l=tree[pos].r=l;
        tree[pos].sum=a[l];
        return;
    }
    build(l,(l+r)/2,lson(pos));
    build((l+r)/2+1,r,rson(pos));
    tree[pos].l=l;tree[pos].r=r;
    tree[pos].sum=tree[lson(pos)].sum+tree[rson(pos)].sum;
}
int Querry(int l,int r,int pos){    //查询区间[l,r]之间的和
    if(l==tree[pos].l && r == tree[pos].r){
        return tree[pos].sum;
    }
    int mid=(tree[pos].l+tree[pos].r)/2;
    if(r<=mid) return Querry(l,r,lson(pos));
    if(l>mid)  return Querry(l,r,rson(pos));

    return Querry(l,mid,lson(pos))+Querry(mid+1,r,rson(pos));
}

void Modify(int x,int y,int pos){       //修改位置为x的叶子节点+y;
    if(tree[pos].l==x && tree[pos].r==x){
        tree[pos].sum+=y;
        return;
    }

    int mid=(tree[pos].l+tree[pos].r)/2;
    if(x<=mid) Modify(x,y,lson(pos));
    else Modify(x,y,rson(pos));
    tree[pos].sum+=y;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    int cases=1;
    while(T--){
        cout << "Case "<<cases++<<":" <<endl;
        int n;
        cin >> n;
        for(int i=1;i<=n;i++)
            cin >> a[i];
        build(1,n,1);
        string s;
        int x,y;
        while(cin >> s)
        {
            if(s[0]=='Q')
                {cin >> x >> y;cout << Querry(x,y,1)<<endl;}
            else if(s[0]=='A')
                {cin >> x >> y;Modify(x,y,1);}
            else if(s[0]=='S')
                {cin >> x >> y;Modify(x,-y,1);}
            else if(s[0]=='E')
                break;
        }
    }

    return 0;
}
