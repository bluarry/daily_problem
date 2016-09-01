#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define maxn 999999999
using namespace std;
#define ERROR -1
#define OK 1
typedef int Status;

typedef struct{
	unsigned int weight; // 存权重
	char pha;		//存字符
	int parent,lchild,rchild;
}HTnode,*HuffmanTree;

int m; //记录一棵树里的节点总数


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

//初始化开始 
Status init(HuffmanTree& HT,int n){
	if(n<=1){
		cout << "警告:字符数太少！"<<endl;
		return ERROR;
	}
	cout << "请依次输入 "<< n << " 个字符 : "<<endl;
	HuffmanTree p;
	m=2*n-1;int i;
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTnode));
	for(i =1,p=HT+1;i<=n;i++,p++){
		cin >> (*p).pha;
		 (*p).parent=0;
		 (*p).lchild=0,(*p).rchild=0;
	}
	
	cout << endl;
	cout << "请依次输入 "<< n << " 个权值(整数) : "<< endl;
	for(i=1,p=HT+1;i<=n;i++,p++)
		cin >> (*p).weight;
	for(;i<=m;i++,p++)
		{(*p).parent=0; (*p).lchild=0,(*p).rchild=0;}
	//建立赫夫曼树
	int s1,s2;
	for(i=n+1;i<=m;i++)
	{
		select(HT,i-1,s1,s2);
		HT[s1].parent=HT[s2].parent=i;
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight + HT[s2].weight;
	}
	
	ofstream file("hfmTree");
	file << n << endl;
	for(i=1;i<=n;i++)
	i==n? file << HT[i].pha<< "\n"  : file << HT[i].pha << " " ;
	for(i=1;i<=m;i++)
		i==m? (file << HT[i].parent<< "\n" ) :( file << HT[i].parent << " ") ;
	for(i=1;i<=m;i++)
		i==m? (file << HT[i].lchild<< "\n"): (file << HT[i].lchild << " ") ;
	for(i=1;i<=m;i++)
		i==m? (file << HT[i].rchild<< "\n" ) : (file << HT[i].rchild << " " );
	file.close();
	
	cout << endl;
	return OK;
}
//************初始化完毕 


void menu(){
	cout << "\t\t******************菜单*********************"<<endl;
	cout << "\t\t    I.初始化           E.编码             "<<endl;
	cout << "\t\t    D.译码             P.印代码文件       "<<endl;
	cout << "\t\t         T.印哈夫曼编码                   "<<endl;
	cout << "\t\t          Q.退出                          "<<endl;
	cout << "\t\t******************end**********************"<<endl;
	cout << "\t\t请输入你的选择 ：";
}

Status readhfmTree(HuffmanTree& HT,int &n){
	ifstream file("hfmTree");
	if(file.is_open())
	{
		file >> n;
		m=2*n-1;
		int i;
		HT=(HuffmanTree)malloc((m+1)*sizeof(HTnode));
		for(i=1;i<=n;i++)  file >> HT[i].pha;
		for(i=1;i<=m;i++)  file >> HT[i].parent;
		for(i=1;i<=m;i++)  file >> HT[i].lchild;
		for(i=1;i<=m;i++)  file >> HT[i].rchild;
			return OK;
	}

	return ERROR;
}
//对文件中的每一个字符编码，存入另一个文件中
Status huffmancoding(HuffmanTree HT,int n){
	ifstream in_1("ToBeTran");
	ofstream out_1("CodeFile");
	int i=1,flag=0;
	while(in_1.good()){
		char x,tem[n+1];
		int start=n,f;
		memset(tem,0,sizeof(tem));
		tem[n]='\0';
		in_1 >> x; cout << x;
		for(i=1;i<=n;i++)
		{
			if(HT[i].pha == x)
			{
				int j=i;
				f=HT[j].parent;
				while(f!=0)
				{
					if(HT[f].lchild==j) tem[--start]='0';
					else tem[--start]= '1';
					j=f;
					f=HT[i].parent;
				}
				out_1 << &tem[start] << endl;
				flag=1;
				break;
			}
		}
	}
	in_1.close();
	out_1.close();
	if(flag)
		return OK;
	else
		return ERROR;

}

int main(){
	char c;
	HuffmanTree HT=NULL;
	int n;
	menu();
	cin >> c;
	while(c!='Q'){
		if(c=='I'){
			system("cls");
			cout << "请输入字符数 : "<< endl; 
			cin >> n;
			if(init(HT,n)== OK)
				cout << "初始化成功!" << endl;
		}
		else if(c=='E'){
			system("cls");
			if(HT==NULL)
			{
				if( readhfmTree(HT,n)+1){
					cout << "读取哈夫曼树成功" << endl;
					cout<< endl;
					if( huffmancoding(HT,n) ){
						cout << "编码成功" << endl;
					}
					else
						cout << "编码失败" << endl; 
				}
				else
				{
					cout << "hfmTree文件不存在，请初始化"<<endl;
				}
			}
			else
			{
					if( huffmancoding(HT,n) ){
						cout << "编码成功" << endl;
					}
					else
						cout << "编码失败" << endl;
			}
		}
		else if(c=='D'){
			system("cls");



		}else if (c=='P')
		{
			system("cls");
			





		}
		else if(c=='T'){
			system("cls");



		}
		else{
			system("cls");
			cout << "输入错误，请检查大小写"<<endl;
		}
		cout <<endl;
		system("pause");
		system("cls");
		menu();
		cin >> c;
	}







	return 0;
}



/*
8
A B C D E F G H
5 29 7 8 14 23 3 11
*/
