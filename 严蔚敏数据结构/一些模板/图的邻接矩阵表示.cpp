#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define INFINITY 99999999
#define  VertexType int
#define MAX_VERTEX_NUM 20

typedef struct Arcell
{
	int adj;	
}AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//邻接矩阵
typedef struct
{
	VertexType vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum,arcnum;
}MGraph;

int locate(MGraph G,VertexType x){
	for(int i=0;i<G.vexnum;i++)
		if(G.vexs[i]==x)
			return i;
		return -1;
}


void CreateGraph(MGraph& G){
	cin >> G.vexnum >> G.arcnum;
	if(G.vexnum >MAX_VERTEX_NUM)exit(-1);

	for(int i=0;i<G.vexnum;i++) //初始化所有的关系为无穷
		for(int j=0;j<G.vexnum;j++){
			G.arcs[i][j].adj=INFINITY;
		}
	for(int i=0;i<G.vexnum;i++)
	{
		cin >> G.vexs[i];
	}

	//有向网
	for(int i=0;i<G.vexnum;i++)
		for(int j=0;j<G.vexnum;j++)
		{
			VertexType x,y;
			cin >> x >> y;
			int ii=locate(G,x);
			int jj=locate(G,y);
			if(ii*jj <0) exit(-1);
			cin >> G.arcs[ii][jj].adj;
		}
}
void printGraph(MGraph G){
	cout << "总共有 " << G.vexnum << " 个顶点, " << G.arcnum << " 个边." <<endl;
	cout << "关系矩阵如下 :" << endl;
	for(int i=0;i<G.vexnum;i++)
		for(int j=0;j<G.vexnum;j++)
		{
			if(j!=G.vexnum-1)
			{
				if(G.arcs[i][j].adj == INFINITY)
					cout << "# ";
				else 
					cout << G.arcs[i][j].adj <<" ";
			}
			else {

				if(G.arcs[i][j].adj == INFINITY)
					cout << "#" << endl;
				else 
					cout << G.arcs[i][j].adj <<endl;
			}
		}
}
int main()
{
	freopen("D:\\1.in","r",stdin);
	MGraph G;
	CreateGraph(G);
	printGraph(G);
	return 0;
}
