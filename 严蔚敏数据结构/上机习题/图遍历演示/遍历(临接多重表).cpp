#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>

using namespace std;

#define STATUS int
#define VertexType string
//邻接多重表
/*****存储结构********/
#define MAX_VERTEX_NUM 40
int XXX=0;
typedef struct EBox{
    int ivex,jvex;
    struct EBox * ilink,*jlink;
    int weight;
}EBox;
//定义链表结点存储结构
typedef struct VexBox{
    VertexType data;
    EBox *firstedg;
}VexBox;
typedef struct{
    VexBox adjmulist[MAX_VERTEX_NUM];
    int vexnum,edgenum;
}AMLGraph;
/*****************/
typedef struct treeedge{
    int a,b;
}tredg;
//编写一个存边的结构
/********************/
/***********************/
//顺序表循环队列的实现

typedef struct
{
    int* elem;
    int rear,front;
}Queue;

void initqueue(Queue& Q){
    Q.elem=new int[MAX_VERTEX_NUM];
    if(!Q.elem)exit(0);
    Q.front=Q.rear=0;
}
void Equeue(Queue &Q,int x)
{
    if((Q.rear+1)%MAX_VERTEX_NUM == Q.front) return ;

    Q.elem[Q.rear]=x;

    Q.rear=(Q.rear+1)%MAX_VERTEX_NUM;
}
void Dqueue(Queue &Q,int& x)
{
    if(Q.front==Q.rear)return ;

    x=Q.elem[Q.front];

    Q.front=(Q.front+1)%MAX_VERTEX_NUM;
}
bool QEmpty(Queue Q){
    return Q.front==Q.rear;
}



/********************/
int located(AMLGraph G,VertexType val){
    int i=0;
    for(;i<G.vexnum;i++)
        if(val == G.adjmulist[i].data)
        {
            return i;
        }
    return -1;
}
//just see
STATUS creatGraph(AMLGraph& G)
{
    cout << "请分别输入顶点数，边数 : ";
        cin >> G.vexnum >> G.edgenum;
        cout << "请输入 " << G.vexnum << " 个顶点 :" << endl;
            for(int i=0;i < G.vexnum ; i++){	//初始化
                cin >> G.adjmulist[i].data;
                G.adjmulist[i].firstedg=NULL;
            }
            cout << "请输入 " << G.edgenum <<" 条边的信息\n";
            cout << "请按照边得尾结点,头结点的方式输入:\n";
            for(int i=0;i<G.edgenum;i++)
            {
                    VertexType st,en;
                    cin >> st >> en;
                    EBox *p=new EBox;
                    if(!p) exit(OVERFLOW);
                    int s=located(G,st);
                    int e=located(G,en);
                    if( s<0 || e <0){
                        cout << "OVERFLOW" <<endl;
                        exit(0);
                    }
                    p->ivex=s;p->jvex=e;	//讲新建的边信息存入
                    //利用头插法建立链表
                    p->ilink=	G.adjmulist[s].firstedg;
                    p->jlink=	G.adjmulist[e].firstedg;
                    G.adjmulist[s].firstedg=G.adjmulist[e].firstedg=p;
            }
}
void visit_node(AMLGraph G,int v){
   // cout << "此时访问的节点为 : "<< G.adjmulist[v].data << endl;
    cout << G.adjmulist[v].data << " ";
}

tredg eedge[100];
int nnum=0;


int getfirstedg(AMLGraph G,int v) //返回与v标号结点的连接的第一个结点位置
{
    EBox *p=G.adjmulist[v].firstedg;
    if (NULL == p) return -1;
    if(p->ivex==v)
    {
        return located(G,G.adjmulist[p->jvex].data);
    }
    else if (p->jvex==v)
    {
        return located(G,G.adjmulist[p->ivex].data);
    }
    return -1;
}
int getnexedg(AMLGraph G,int v,int w){
        //从图G标号为v的结点出发,一直找到标号为w的下一个结点的位置
    EBox *p=G.adjmulist[v].firstedg;

    //总之就是返回v这条链的w的下一个元素
    while(1)
    {
        if(p->ivex==v && p->jvex!=w )
               p=p->ilink;
        else if(p->jvex==v && p->ivex!=w)
                p=p->jlink;
        if(NULL == p) break;
        if(p->jvex==w) break;
        if(p->ivex==w) break;
    }
        if(NULL == p) return -1;
        if(p->jvex==w && p->ilink!=NULL)
        {
            p=p->ilink;
            if(p->ivex==v)return p->jvex;
            else return p->ivex;
        }
        else if(p->ivex==w && p->jlink!=NULL)
        {
            p=p->jlink;
            if(p->jvex==v)return p->ivex;
            else return p->jvex;
        }
        else return -1;

}

bool visit[ MAX_VERTEX_NUM];
void dfs(AMLGraph G,int v) {
        visit[v]=true;
        visit_node(G,v);
        for(int w=getfirstedg(G,v); w >=0 ;w=getnexedg(G,v,w)){ //dfs遍历
            if(!visit[w])//w为每一个结点的下标
            {
                eedge[nnum].a=v;
                eedge[nnum].b=w;
                nnum++;
                dfs(G,w);
            }
        }
}

int xxx;
void dfstra(AMLGraph G) {
    VertexType x;
        memset(visit,false,sizeof(visit));
        cout << "请输入起点结点 :\n";
         cin >> x;
         xxx=located(G,x);
         if(xxx<0) exit(OVERFLOW);
        for(int i=xxx;i<G.vexnum;i++){
            if(!visit[i])
            {
                dfs(G,i);
            }
        }
        for(int i=xxx;i>=0;i--){
            if(!visit[i])
            {
                dfs(G,i);
            }
        }
}

void bfstra(AMLGraph G){
    Queue Q;
     memset(visit,false,sizeof(visit));
     initqueue(Q);
    for(int i=xxx;i<G.vexnum;i++){
        if(!visit[i]){
            visit[i]=true;visit_node(G,i);
            Equeue(Q,i);
            while(!QEmpty(Q)){
                int u,w;
                Dqueue(Q,u);
                for(w = getfirstedg(G,u); w >=0 ;w=getnexedg(G,u,w)){ //dfs遍历
                    if(!visit[w])//w为每一个结点的下标
                    {
                        eedge[nnum].a=u;
                        eedge[nnum].b=w;
                        nnum++;
                         visit[w]=true;visit_node(G,w);
                        Equeue(Q,w);
                    }//if
                }//for
            }//while
          }//if
    }//for

    for(int i=xxx;i>=0;i--){
        if(!visit[i]){
            visit[i]=true;visit_node(G,i);
            Equeue(Q,i);
            while(!QEmpty(Q)){
                int u,w;
                Dqueue(Q,u);
                for(w = getfirstedg(G,u); w >=0 ;w=getnexedg(G,u,w)){ //dfs遍历
                    if(!visit[w])//w为每一个结点的下标
                    {
                        eedge[nnum].a=u;
                        eedge[nnum].b=w;
                        nnum++;
                         visit[w]=true;visit_node(G,w);
                        Equeue(Q,w);
                    }//if
                }//for
            }//while
          }//if
    }//for


}//bfs
void  printt(AMLGraph G, tredg x){
    cout << G.adjmulist[x.a].data << " ";
    cout << G.adjmulist[x.b].data <<endl;
}
int main()
{
    freopen("./in","r",stdin);
        AMLGraph G;
        //建立表
        creatGraph(G);
        //dfs输出每个结点相关的边结点,从第一个结点出发dfs
        cout << "接下来是dfs访问序列 :" << endl;
        dfstra(G);
        cout <<endl;

        cout << "\nbfs生成树的边集为:\n";
        for(int i=0;i<nnum;i++)
            printt(G,eedge[i]);
        nnum=0;



        cout << "\n接下来是bfs访问序列 :" << endl;
        //bfs输出节点
        bfstra(G);
        cout << endl;
        cout << "dfs生成树的边集为:\n";
        for(int i=0;i<nnum;i++)
            printt(G,eedge[i]);

    return 0;

}

