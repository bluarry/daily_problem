#include <iostream>
#include <cstdio>
#include <string>
#define INIFITY 32767
#define MAX_VERTEX_NUM 1000

using namespace std;

typedef int adjtype;
typedef string vextype;

typedef struct{
    vextype *vex;//顶点信息
    adjtype **adj;//边的权值
    int vetexnum,adjnum;
}Graph;

int locate(Graph G,vextype a)
{
    int i=0;
    for(;i<G.vetexnum;i++) if(G.vex[i]==a) return i;
    return -1;
}


int CreatGraph(Graph& G)
{
    cout << "请依次输出顶点数目，边的数目 ：" <<endl;
    cin >> G.vetexnum >> G.adjnum;
    G.vex=new vextype[G.vetexnum];
    if(!G.vex) return 0;
    cout << "分别输入结点的信息： "<< endl;
    for(int i=0;i<G.vetexnum;i++)
    {
        cin >> G.vex[i];
    }
    cout << "请分别输入边以及权重 ： " << endl;

     G.adj=new adjtype* [G.vetexnum];   //new 一个二维数组
     for(int i=0;i<G.vetexnum;i++)
         G.adj[i]= new adjtype[G.vetexnum];

    if(!G.adj) return 0;
    for(int i=0;i<G.vetexnum;i++)
        for(int j=0;j<G.vetexnum;j++)
        {
            G.adj[i][j]=INIFITY;
        }

    vextype a,b;
       for(int i=0;i<G.adjnum;i++)
       {
           int weight;
            cin >> a >> b >> weight;
            int x=locate(G,a);
            int y=locate(G,b);
            if(x==-1 | y==-1)
            {
                cout << "输入的边有误";
                return 0;
            }
            G.adj[x][y]=G.adj[y][x]=weight;
       }
    return 1;
}
void MinSpanTree_Prim(Graph G, vextype u);//prim 算法

int main()
{
    freopen("./in","r",stdin);
    Graph G;
    if(!CreatGraph(G))
    {
        cout << "创建图失败！";
    }

    //接下来是prim算法

     cout << "请输入起始结点 ： ";

    vextype a;
    cin >> a;
    MinSpanTree_Prim(G,a);
    return 0;
}

typedef struct
{
    int adjvex;
    adjtype lowcost;
}minside[MAX_VERTEX_NUM];

int mininum(minside L,Graph G)
{
    int i=0;
    while(!L[i].lowcost) i++;
    int min=L[i].lowcost;
    int k=i;
    for(int j=i+1;j<G.vetexnum;j++)
        if(L[j].lowcost>0 && L[j].lowcost<min)
        {
            min=L[j].lowcost;
            k=j;
        }
    return k;
}
void MinSpanTree_Prim(Graph G,vextype u)
{
    minside closedg;
    int k=locate(G,u);

    for(int i=0;i<G.vetexnum;i++)
    {
        closedg[i].adjvex=k;
        closedg[i].lowcost=G.adj[k][i];
    }
    closedg[k].lowcost=0;

    cout << "生成树的边集如下 : "<< endl;
    int j;
    for(int i=1;i<G.vetexnum;i++)
    {
        k=mininum(closedg,G);
        cout << G.vex[closedg[k].adjvex] << "----" << G.vex[k]<< endl;
        closedg[k].lowcost=0;
        for(j=0;j<G.vetexnum;j++)
            if(G.adj[k][j] < closedg[j].lowcost)
            {
                   closedg[j].adjvex=k;
                   closedg[j].lowcost=G.adj[k][j];
            }
    }
}

