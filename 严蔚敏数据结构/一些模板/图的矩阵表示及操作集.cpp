#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

#define INFINITY INT_MAX;//定义无穷大
typedef string InfoType;
struct VertexType{
	string name;
};
typedef int VRType;//定义顶点之间的关系为整形
#define MAX_VERTEX_NUM 30 //定义最大的顶点数
enum GraphKind{DG,DN,UDG,UDN};//定义图的类型，，分别为有向图，有向网，无向图，无向网
typedef struct { // 定义每一条边的信息
	VRType adj; 	//顶点的关系 1/权重
	InfoType* info;  //这条边的相关信息
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct {
	VertexType vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum,arcnum;
	GraphKind kind;
}MGraph;
//定义数组表示



void InputArc(InfoType* &arc){				//输入某条弧的信息
	string s;
	cout << "请输入该弧的所有信息 : ";
	cin >>s;
	arc = new string;
	arc=&s;
}
void Input(VertexType &ver){ 			//输入定点信息
	cin >> ver.name;
}




int locateVex(MGraph G,VertexType u){   //找某一节点的位置
	for(int i=0;i<G.vexnum;i++)
		if(u.name == G.vexs[i].name)
			return i;
return -1;
}
void CreateDG(MGraph& G){
	cout << "请输入顶点的数，弧数，以及是否含义相关信息(是:1 否:0) : ";
	int IncInf;
	cin >> G.vexnum >> G.arcnum >> IncInf ;
	cout << "请输入" << G.arcnum<< "个顶点的值(名称<"<<30 << "个字符" << endl;
	 for(int i=0;i<G.vexnum;i++)	//输入每个点的信息
	 	Input(G.vexs[i]);
	 for(int i=0;i<G.vexnum;i++)	//初始化
	 	for(int j=0;j<G.vexnum;j++)
	 	{
	 		G.arcs[i][j].adj=0;
	 		G.arcs[i][j].info=NULL;
	 	}
	 cout << "请输入 "<< G.arcnum << " 条弧的弧头, 弧尾: " <<endl;
	 VertexType v1,v2;
	 for(int k=0;k<G.arcnum;k++){
	 	cin >> v1.name >> v2.name;
	 	int i=locateVex(G,v1);
	 	int j=locateVex(G,v2);

	 	G.arcs[i][j].adj=1;

	 	if(IncInf)
	 		InputArc(G.arcs[i][j].info);
	 }
	 G.kind=DG;
}
void CreateDN(MGraph& G){
	cout << "请输入顶点的数，弧数，以及是否含义相关信息(是:1 否:0) : ";
	int IncInf;
	cin >> G.vexnum >> G.arcnum >> IncInf ;
	cout << "请输入" << G.arcnum<< "个顶点的值(名称<"<<30 << "个字符" << endl;
	 for(int i=0;i<G.vexnum;i++)	//输入每个点的信息
	 	Input(G.vexs[i]);
	 for(int i=0;i<G.vexnum;i++)	//初始化
	 	for(int j=0;j<G.vexnum;j++)
	 	{
	 		G.arcs[i][j].adj=0;
	 		G.arcs[i][j].info=NULL;
	 	}
	 cout << "请输入 "<< G.arcnum << " 条弧的弧头, 弧尾: " <<endl;
	 



}
void CreateUDG(MGraph& G){

}
void CreateUDN(MGraph& G){

}







int CreateGraph(MGraph& G){
	cout << "请输入图G的类型(有向图 :0 无向图 :1 有向网 :2 无向网 :3) :" ;
	int x;
	cin >> x;
	G.kind=(GraphKind)x;
	switch(G.kind){
		case DG:
				CreateDG(G);
				break;
		case DN :
				CreateDN(G);
				break;
		case UDG :
				CreateUDG(G);
				break;
		case UDN :
				CreateUDN(G);
				break;		
	}
}







int main()
{	












	return 0;
}
