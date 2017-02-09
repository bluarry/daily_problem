#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
const int maxn=10000+10;
const int INF=999999999;
int in_order[maxn],post_order[maxn],lch[maxn],rch[maxn]; //lch为树的左子树,rch为树的右子树
int n;

bool reade_list(int *a)
{
    string line;
    if(!getline(cin,line)) return false;
    stringstream ss(line);
    n=0;
    int x;
    while (ss >> x) {
        a[n++]=x;
    }
    return n>0;
}
int best_sum,best;

//根据in_order[L1,R1]和post_order[L2,R2]建立一颗树,并返回树跟i
int  build(int L1,int R1,int L2,int R2)
{
    if(L1>R1) return 0;
    int root=post_order[R2];
    int p=L1;
    while(in_order[p]!=root)p++;
    int cnt=p-L1;
    lch[root]=build(L1,p-1,L2,L2+cnt-1);
    rch[root]=build(p+1,R1,L2+cnt,R2-1);//R2是根节点故从R2-1开始
    return root;
}
void dfs(int v,int sum)
{
    sum+=v;
    if(!lch[v]&& !rch[v])
    {   //到叶子了
        if(sum < best_sum || sum == best_sum && v<best)
        {best=v;best_sum=sum;}
    }
    if(lch[v]) dfs(lch[v],sum);
    if(rch[v])  dfs(rch[v],sum);
}
int main()
{
    while(reade_list(in_order))
    {
        reade_list(post_order);

        build(0,n-1,0,n-1);
        best_sum=INF;
        dfs(post_order[n-1],0);
        cout << best << endl;
    }
    return 0;
}
