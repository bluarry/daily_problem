#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define MAX_VERTEX_NUM 100
#define VertexType int

struct ArcNod{
	int adj;
	ArcNod *next;
};
typedef struct vnode
{
	VertexType data;	
	ArcNod *firstarc;
}adjlist[MAX_VERTEX_NUM];
typedef struct 
{
	adjlist vers;
	int vexnum,arcnum;
}ALGraph;
int locate(ALGraph G,VertexType x){
	for(int i=0;i<G.vexnum;i++)
		if(G.vers[i].data==x)
			return i;
return -1;
}



void creatGraph(ALGraph& G){
	cin >> G.vexnum >> G.arcnum;
	if(G.vexnum > MAX_VERTEX_NUM) exit(-1);
	for(int i=0;i<G.vexnum;i++)
	{
		cin >> G.vers[i].data;
		G.vers[i].firstarc=NULL;
	}

	for(int i=0;i<G.arcnum;i++){
		VertexType x,y;
		cin >> x >> y;
		int ii=locate(G,x);
		int jj=locate(G,y);
		if(ii*jj<0) exit(-1);

		if(!G.vers[ii].firstarc)
		{
			ArcNod *q=(ArcNod *)malloc(sizeof(ArcNod));
			q->adj=jj;
			q->next=NULL;
			G.vers[ii].firstarc=q;
		}
		else
		{
		ArcNod *q,*p=G.vers[ii].firstarc;
		while(p->next) p=p->next;
		q=(ArcNod *)malloc(sizeof(ArcNod));
		q->adj=jj;
		q->next=NULL;
		p->next=q;
		} 
	
	}
}
void printGraph(ALGraph G){
	for(int i=0;i<G.vexnum;i++)
	{
		cout << G.vers[i].data << " ";
		ArcNod *p=G.vers[i].firstarc;
		while(p)
		{
			cout << G.vers[p->adj].data << " ";
			p=p->next;
		}
		cout << endl;
	}
}
int main()
{	
	freopen("D:\\1.in","r",stdin);
	ALGraph G;
	creatGraph(G);
	printGraph(G);
	return 0;
}

/*
6 10
1 2 3 4 5 6
1 2
1 4
2 3
3 1
3 6
4 3
4 6
5 4
6 1
6 5

*/
