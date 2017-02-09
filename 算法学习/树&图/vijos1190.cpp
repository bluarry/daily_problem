#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=1000000;
int n,m;
typedef struct{
    int v1,v2,w;
}edg;
edg node[maxn],result[maxn];
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
    int k=1;    //选出的边数.;k==0存节点个数

    while(j<m && k <m)
    {
        int s1=vset[node[j].v1];
        int s2=vset[node[j].v2];
        if(s1!=s2)
        {
            result[k].v1=s1;
            result[k].v2=s2;
            result[k].w=node[j].w;
            k++;
            for(int i=0;i<=n;i++)       //细心!!错误点!!少了:
                if(vset[i]==s2)
                    vset[i]=s1;
        }
    j++;
    }
        // for(int i=0;i<=n;i++) cout << vset[i] << " ";
        // cout << endl;
    result[0].w=k;
    delete vset;
}
int main() {
    cin >> n >> m;
    for(int i=0;i<m;i++) cin >> node[i].v1 >> node[i].v2 >> node[i].w;
    select();
    int mm=0;
    for(int i=1;i<result[0].w;i++)
    {
        //cout << result[i].v1 << " "<<result[i].v2 <<endl;
        if(result[i].w>mm) mm=result[i].w;
    }
    cout << result[0].w-1 << " "<< mm <<endl;
    return 0;
}
