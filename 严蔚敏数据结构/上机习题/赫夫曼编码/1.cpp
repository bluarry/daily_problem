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
	unsigned int weight; // ��Ȩ��
	char pha;		//���ַ�
	int parent,lchild,rchild;
}HTnode,*HuffmanTree;

int m; //��¼һ������Ľڵ�����


int min_min(HuffmanTree t,int i){
	int j,m;
	unsigned k=maxn;
	for(j=1;j<=i;j++)
		if(t[j].weight < k && t[j].parent == 0)
			k=t[j].weight,m=j;
	t[m].parent=1;  //������ص㣬��Ϊ���ڶ��ε������ҵڶ�С�����Ե�һС��Ϊ1.(������Щ��㲢δ���뵽�շ������У����Ը���֮����Ӱ��)
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

//��ʼ����ʼ 
Status init(HuffmanTree& HT,int n){
	if(n<=1){
		cout << "����:�ַ���̫�٣�"<<endl;
		return ERROR;
	}
	cout << "���������� "<< n << " ���ַ� : "<<endl;
	HuffmanTree p;
	m=2*n-1;int i;
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTnode));
	for(i =1,p=HT+1;i<=n;i++,p++){
		cin >> (*p).pha;
		 (*p).parent=0;
		 (*p).lchild=0,(*p).rchild=0;
	}
	
	cout << endl;
	cout << "���������� "<< n << " ��Ȩֵ(����) : "<< endl;
	for(i=1,p=HT+1;i<=n;i++,p++)
		cin >> (*p).weight;
	for(;i<=m;i++,p++)
		{(*p).parent=0; (*p).lchild=0,(*p).rchild=0;}
	//�����շ�����
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
//************��ʼ����� 


void menu(){
	cout << "\t\t******************�˵�*********************"<<endl;
	cout << "\t\t    I.��ʼ��           E.����             "<<endl;
	cout << "\t\t    D.����             P.ӡ�����ļ�       "<<endl;
	cout << "\t\t         T.ӡ����������                   "<<endl;
	cout << "\t\t          Q.�˳�                          "<<endl;
	cout << "\t\t******************end**********************"<<endl;
	cout << "\t\t���������ѡ�� ��";
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
//���ļ��е�ÿһ���ַ����룬������һ���ļ���
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
			cout << "�������ַ��� : "<< endl; 
			cin >> n;
			if(init(HT,n)== OK)
				cout << "��ʼ���ɹ�!" << endl;
		}
		else if(c=='E'){
			system("cls");
			if(HT==NULL)
			{
				if( readhfmTree(HT,n)+1){
					cout << "��ȡ���������ɹ�" << endl;
					cout<< endl;
					if( huffmancoding(HT,n) ){
						cout << "����ɹ�" << endl;
					}
					else
						cout << "����ʧ��" << endl; 
				}
				else
				{
					cout << "hfmTree�ļ������ڣ����ʼ��"<<endl;
				}
			}
			else
			{
					if( huffmancoding(HT,n) ){
						cout << "����ɹ�" << endl;
					}
					else
						cout << "����ʧ��" << endl;
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
			cout << "������������Сд"<<endl;
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
