#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#define maxn 99999999
using namespace std;

typedef struct{
	unsigned int weight;
	unsigned int parent,lchild,rchild;
}HTNode,* HuffmanTree;

typedef char * * Huffmancode;

int min_min(HuffmanTree t,int i){
	int j,m;
	unsigned k=maxn;
	for(j=1;j<=i;j++)
		if(t[j].weight < k && t[j].parent == 0)
			k=t[j].weight,m=j;
	t[m].parent=1;  //这个是重点，因为，第二次调用是找第二小，所以第一小置为1.(由于这些结点并未加入到赫夫曼树中，所以更改之后无影响)
	return m;
}
void select(HuffmanTree t,int i,int& s1,int & s2){
	s1=min_min(t,i);
	s2=min_min(t,i);
	if(s1>s2)
	{
		int tem=s1;
		s1=s2;
		s2=tem;
	}
}

void Huffmancoding(HuffmanTree& HT,Huffmancode& HC,int *w,int n){
	int i,s1,s2;
	HuffmanTree p;
	if(n<=1) {
		cout << "警告：节点数太少!";
		return ;
	}
	int m=2*n-1;
//*****************初始化将所有的结点看作一棵树，将父节点，孩子结点置为0
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
	for(p=HT+1,i=1;i<=n;i++,p++,w++){ 
		(*p).weight= *w;
		 (*p).parent=0; 
		 (*p).lchild=0;
		  (*p).rchild=0;
	}
	for(;i<=m;i++,p++)
		(*p).parent=0;
//******************建立赫夫曼树
	for(i=n+1;i<=m;i++)
	{
		select(HT,i-1,s1,s2);
		HT[s1].parent=HT[s2].parent=i;
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight + HT[s2].weight;
	}

//从叶结点到根节点求编码

	HC=(Huffmancode)malloc((n+1)*sizeof(char *));
	char *cd=(char *)malloc(sizeof(char)*n);
	cd[n-1]='\0';
	int start;
	unsigned c,f;
	for(i=1; i<=n;i++ )
	{
		start=n-1;
		for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
			if(HT[f].lchild==c)
				cd[--start]='0';
			else
				cd[--start]='1';
		HC[i]=(char * )malloc((n-start)*sizeof(char));
		strcpy(HC[i],&cd[start]);
	}
	free(cd);
}

int main()
{	
	HuffmanTree HT;
	Huffmancode HC;
	int n,i;
	cout << "请输入权的个数(>1): ";
	cin >> n;
	int* w=(int *)malloc(n*sizeof(int));
	cout << "请输入 "<<n<<" 个权重(整形): ";
	for(int i=0;i<=n-1;i++)
		cin >> w[i];
	Huffmancoding(HT,HC,w,n);   //赫夫曼编码存入HC中,w存的是权重。
	for(i=1;i<=n;i++)
		cout << HC[i] << endl;

	return 0;
}