#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
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

//求a节点的下标
int locate(Graph G,vextype a)
{
    int i=0;
    for(;i<G.vetexnum;i++) if(G.vex[i]==a) return i;
    return -1;
}

//创建有向图
int CreatGraph(Graph& G)
{
    cout << "请依次输入有向图顶点数目，边的数目 ：" <<endl;
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
            if(x==-1 || y==-1)
            {
               cout << "输入的边有误";
                return 0;
            }
            G.adj[x][y]=weight;
       }
    return 1;
}

void Road_print(Graph G,int *pre,int x,int v0,int *dist)
{
    int y=x;
    if(x==v0) return ;
    stack<int> s;
    s.push(x);
    for(;pre[x]!=-1;x=pre[x])
    {
        s.push(pre[x]);
    }
    if(x!=v0)
    {
        cout<<G.vex[v0] << "到 " << G.vex[y] << " 无路径"<< endl;
        return ;
    }


    cout <<G.vex[v0] << "到 " << G.vex[y] << " 的路径为 : ";

    while(!s.empty())
    {
        cout << G.vex[s.top()] << " ";
        s.pop();
    }
    cout << "\n最短路径长度为 :" << dist[y];
    cout << endl;
}



void Djstra(Graph G,int v0)
{
    int dist[G.vetexnum];
    int pre[G.vetexnum];
    bool S[G.vetexnum];

    //初始化dist为V0的邻接点
    //将集合S置为空，并将前驱设置为v0
    for(int i=0;i<G.vetexnum;i++)
    {
        dist[i] = G.adj[v0][i];
        S[i] = false;
        if(dist[i] == INIFITY)
           pre[i] = -1;
        else
           pre[i] = v0;
    }

    dist[v0]=0;
    S[v0]=true;
    for(int i=1; i<G.vetexnum; i++)
        {
             int mindist = INIFITY;         //最小的元素
             int u = v0;                    //记录dist中不是S集合最小元素的下标
             for(int j=0; j<G.vetexnum; ++j)
                if((!S[j]) && dist[j]<mindist)
                {
                      u = j;
                     mindist = dist[j];
                }
             S[u] = true;
             for(int j=0; j<G.vetexnum; j++)
                 if((!S[j]) && (dist[u] + G.adj[u][j] < dist[j]))
                 {
                         dist[j] = dist[u] + G.adj[u][j];
                         pre[j] = u;
                  }
        }
    for(int i=0;i<G.vetexnum;i++)
        Road_print(G,pre,i,v0,dist);
}

int main()
{
    freopen("./in","r",stdin);
    Graph G;
    if(!CreatGraph(G))
    {
        cout << "创建图失败！";
    }
//    for(int i=0;i<G.vetexnum;i++)
//        for(int j=0;j<G.vetexnum;j++)
//            j==G.vetexnum-1 ? cout << G.adj[i][j] << endl: cout << G.adj[i][j]<<" ";

    cout << "请输入起始节点 :\n";
    vextype x;
    cin >> x;
    Djstra(G,locate(G,x));

    return 0;
}

