#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;

typedef string vextype;


typedef struct Box{
    int date;
    struct Box* next;
}Box;

typedef struct {
    int in;
    Box* first;
}Gvex;
typedef struct
{
    vextype* vex;
    Gvex* adj;
    int vexnum,edgnum;
}AGraph;


int locate(AGraph G,vextype a)
{
    for(int i=0;i<G.vexnum;i++)
        if(a==G.vex[i])
            return i;

    return -1;
}
int creatGraph(AGraph& G)
{
    cout << "请输入图的结点数目，边的个数 :";
    cin >> G.vexnum >> G.edgnum;
    G.vex=new vextype[G.vexnum];
    if(!G.vex) return 0;

    G.adj=new Gvex[G.vexnum];
    if(!G.adj) return 0;
    for(int i=0;i<G.vexnum;i++)
    {
        G.adj[i].in=0;
        G.adj[i].first=NULL;
    }
    cout << "请输入结点 ：";
    for(int i=0;i<G.vexnum;i++)
        cin >>G.vex[i];
    cout << "输入边 ："<<endl;
    for(int i=0;i<G.edgnum;i++)
    {
          vextype a,b;
          cin >> a >> b;
          int x=locate(G,a);
          int y=locate(G,b);
          if(x < 0 || y < 0 )
                return 0;
          G.adj[y].in++;
          Box *te=new Box;       //头插法
          te->date=y;
          te->next=G.adj[x].first;
          G.adj[x].first=te;
    }
}
void tpsort(AGraph G)
{
    int result[G.vexnum],k=0;
    stack<int> s;
    for(int i=0;i<G.vexnum;i++)
    {
       // cout << "G.adj[" << i << "].in ="<<G.adj[i].in << " " << endl;
        if(G.adj[i].in==0)
            s.push(i);
    }
    while(!s.empty())
    {
        int tt=s.top();s.pop();
        result[k++]=tt;

        Box *B=G.adj[tt].first;
        while(B)
        {
            G.adj[B->date].in --;
            if(G.adj[B->date].in==0)
            {
                s.push(B->date);
            }
            B=B->next;
        }
    }
     if(G.vexnum==k)
     {
         cout << "拓扑排序结果为 : ";
        for(int i=0;i<k;i++)
        {
            cout << G.vex[result[i]] << " ";
        }
        cout << endl;
     }
     else
     {
        cout << "图中有回路"<< endl;
     }
}
int main()
{
    freopen("./in1","r",stdin);
    AGraph G;
    if(!creatGraph(G))
    {
        cout << "创建图失败"<<endl;
        exit(-1);
    }

    tpsort(G);

    return 0;
}

