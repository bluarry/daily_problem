#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#define INFINITY INT32_MAX /* 最大值∞ */
#define MAX_EDGE 100 /* 最大边数 */
using namespace std;

typedef string vextype;


typedef struct MSTEdge
{  int vex1 , vex2 ;
   int weight ;
} MSTEdge ;


typedef struct {
    int vexnum,adgnum;
    vextype* vex;
    MSTEdge* edglist;
}Graph;

int locate(Graph G,vextype a)
{
    for(int i=0;i<G.vexnum;i++)
        if(a==G.vex[i])
            return i;
    return -1;
}


int creatGraph(Graph &G)
{
    cout << "输入顶点数以及边的个数 ：";
    cin >> G.vexnum >> G.adgnum;
    G.vex=new vextype[G.vexnum];
    if(!G.vex) return 0;
    G.edglist=new MSTEdge[G.adgnum];
    if(!G.edglist) return 0;
    cout << "请输入各个结点的信息 :" <<endl;
    for(int i=0;i<G.vexnum;i++)
    {
           cin >> G.vex[i];
    }
    cout << "请输入边的信息 ：" << endl;
    for(int i=0;i<G.adgnum;i++)
    {
        vextype a,b;
        cin >> a >> b >> G.edglist[i].weight;
        int x=locate(G,a);
        int y=locate(G,b);
        if(x==-1 || y==-1)
        {
            return 0;
        }
        G.edglist[i].vex1=x;
        G.edglist[i].vex2=y;
    }
    return 1;
}


//排序比较用
bool cmp(MSTEdge a,MSTEdge b)
{
    return a.weight < b.weight;
}

  MSTEdge RE[MAX_EDGE];
//克鲁斯卡尔求最小生成树
void krukal_MST(Graph &G)
{
    //结果数组

    int *vset=new int[G.vexnum]; //申请表示数组
    if(!vset)
    {
        cout << "OVERFLOW"<<endl;
        exit(-1);
    }
    //每一个顶点和自己在一个集合里
    for(int i=0;i<G.vexnum;i++)
    {
        vset[i]=i;
    }

    //将边排序，按照权值最小

    sort(G.edglist,G.edglist+G.adgnum,cmp);

    //kruskal 求最小生成树

    int j=0,k=1;
    while(j<G.vexnum-1 && k < G.adgnum)
    {
        int s1=vset[G.edglist[j].vex1];
        int s2=vset[G.edglist[j].vex2];
        if(s1!=s2)
        {
            RE[k].vex1=G.edglist[j].vex1;
            RE[k].vex2=G.edglist[j].vex2;
            RE[k].weight=G.edglist[j].weight;
            k++;
            for(int i=0;i<G.vexnum;i++)
            {
                if(vset[i]==s2)
                    vset[i]=s1;
            }
        }
       j++;
    }
    RE[0].weight=k; //第0位存的是数量
    delete vset;

}


int main()
{
    freopen("./in","r",stdin);
    Graph G;

    if(!creatGraph(G))
    {
        cout << "创建图失败"<<endl;
        exit(-1);
    }

    krukal_MST(G);


    cout << "生成树的边集为 : "<<endl;
    for(int i=1;i<RE[0].weight;i++)
    {
        cout << G.vex[RE[i].vex1] << "---"<<G.vex[RE[i].vex2]<<endl;
    }
    return 0;
}

