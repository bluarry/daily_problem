#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=500+10;
struct Point{
    int x,y;
}p[maxn];
struct Edge{
    int u,v;
    double w;
}edge[maxn*maxn+10];

int S,P,cnt,num;

int pow2(int x)
{
    return x*x;
}

double calc_dist(Point a,Point b){
    return ( sqrt( double(pow2(a.x-b.x)+pow2(a.y-b.y)) )  );
}
bool cmp(Edge a,Edge b){
    return a.w<b.w;
}

/******************并查集************************/
int fa[maxn];
int getfa(int p){
    if(fa[p]!=p)
    fa[p]=getfa(fa[p]);
    return fa[p];
}
void merge(int x,int y){
    fa[getfa(x)]=getfa(y);
}
/******************end**************************/
double d[maxn*maxn+10];
//需要并查集
void krukal()
{
    num=0;//所选边的个数
    int x=0;
    for(int i=0;i<cnt;i++)
    {
        if(getfa(edge[i].u)!=getfa(edge[i].v))        //如果一个边的两个定点不属于同一个集合，那么就将此边加入所选边集
        {
            merge(edge[i].u,edge[i].v);
            d[num++]=edge[i].w;
            x++;
            if(x==P-1) return ;
        }
    }
}

//求出最小生成树的边集，那么可以替换掉最大的S-1个边
//剩下的最大的边即为所求结果D
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&S,&P);
        for(int i=1;i<=P;i++)       //点的输入顺序即为编号
        {
            scanf("%d%d",&p[i].x,&p[i].y);
        }
        //得到点之后，应该枚举所有可能的边并排序
        cnt=0;//边的个数
        for(int i=1;i<=P;i++)
            for(int j=i+1;j<=P;j++)
            {
                edge[cnt].u=i;
                edge[cnt].v=j;
                edge[cnt++].w=calc_dist(p[i],p[j]);
                edge[cnt].u=j;
                edge[cnt].v=i;
                edge[cnt++].w=calc_dist(p[i],p[j]);
            }
//        for(int i=0;i<cnt;i++)
//            cout << edge[i].u << " " << edge[i].v << " " << edge[i].w << endl;
            sort(edge,edge+cnt,cmp);
//        for(int i=0;i<cnt;i++)
//            cout << edge[i].u << " " << edge[i].v << " " << edge[i].w << endl;


           for(int i=1;i<=P;i++) fa[i]=i;   //并查集初始化
            memset(d,0,sizeof(d));
           krukal();

           //此时d数组里存的是选的边集
           //替换掉S-1个边，那么最后的答案应该是 d[P-(S-1)];
//           for(int i=0;i<num;i++)
//                printf("%.2lf\n",d[i]);

//           printf("%d %d %d\n",num,P,P-S-1);
           if(S!=0)
            printf("%.2lf\n",d[P-(S+1)]);
            else
              printf("%.2lf\n",d[P-(S+2)]);
    }


    return 0;
}