#include <iostream>
#include <cstdio>
using namespace std;

#define INFINITY INT_MAX;//定义无穷大
typedef int InfoType;
typedef int VRType;//定义顶点之间的关系为整形
#define MAX_VERTEX_NUM 30 //定义最大的顶点数
enum GraphKind{DG,DN,UDG,UDN};//定义图的类型，，分别为有向图，有向网，无向图，无向网
typedef struct { // 定义每一条边的信息
	VRType adj; 	//顶点的关系 1/权重
	InfoType* info;  //这条边的相关信息
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	






int main()
{	












	return 0;
}