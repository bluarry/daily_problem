#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=1000000;
int n,m,kk,ans;
int qq;
typedef struct{
    int v1,v2,w;
}edg;
edg node[maxn];
bool cmp(edg a,edg b)
{
    return a.w < b.w;
}
void select()
{
    int *vset=new int [n+1];

    sort(node,node+m,cmp);

    for(int i=0;i<=n;i++) vset[i]=i;

    int j=0;
    qq=n;
    while(j<m)
    {
        int s1=vset[node[j].v1];
        int s2=vset[node[j].v2];
        if(s1!=s2)
        {
            if(qq <= kk) break;
            ans+=node[j].w;
            qq--;
            for(int i=0;i<=n;i++)       //细心!!错误点!!少了:
                if(vset[i]==s2)
                    vset[i]=s1;
        }
    j++;
    }

    delete vset;
}
int main() {
    cin >> n >> m >> kk;
    for(int i=0;i<m;i++) cin >> node[i].v1 >> node[i].v2 >> node[i].w;
    select();
    if(qq==kk) cout <<ans <<endl;
    else cout << "No Answer"<<endl;
    return 0;
}
