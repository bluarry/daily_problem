#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#define maxn 999999999
using namespace std;
#define ERROR 0
#define OK 1
typedef int Status;

typedef struct{
	unsigned int weight; // ��Ȩ��
	char pha;		//���ַ�
	int parent,lchild,rchild;
}HTnode,*HuffmanTree;

int m; //��¼һ������Ľڵ�����

typedef char * * Huffmancode;

Huffmancode HC; //��hc�б������


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
		{(*p).pha=' ';(*p).parent=0; (*p).lchild=0,(*p).rchild=0;}
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
		i==m? (file << HT[i].weight<< "\n" ) :( file << HT[i].weight << " ") ;
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
		for(i;i<=m;i++) 	HT[i].pha=' ';
		for(i=1;i<=m;i++) 	file >> HT[i].weight;
		for(i=1;i<=m;i++)  file >> HT[i].parent;
		for(i=1;i<=m;i++)  file >> HT[i].lchild;
		for(i=1;i<=m;i++)  file >> HT[i].rchild;
			return OK;
	}

	return ERROR;
}
//���ļ��е�ÿһ���ַ����룬������һ���ļ���
Status huffmancoding(HuffmanTree HT,int n){
		//Ԥ������� 
	int i;
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
	//��Ҫ������ļ����бȶ�
	ifstream in_1("ToBeTran");
	if(!in_1.is_open()){
		cout << "�ļ���ʧ��!";
			return ERROR;
	}
	ofstream out_1("CodeFile");
	if(!out_1.is_open()){
		cout << "�ļ���ʧ��!";
		return ERROR;
	}

	while(!in_1.eof()){
		char x;
		in_1 >> x;
		for(int i=1;i<=n;i++){

			if(HT[i].pha == x)
			{
				out_1 << HC[i];
			}

		}
	}
	in_1.close();
	out_1.close();
}
//��Codefile�е��ļ����룬���浽TextFile
Status Traslatecode(HuffmanTree HT,int n){
	ifstream icin("CodeFile");
	if(!icin.is_open())
	{
		cout << "�����ļ������ڣ�"<< endl;
		return ERROR;
	}
	ofstream icout("TextFile");
	if(!icout.is_open())
	{
		cout << "���ļ�ʧ��"<< endl;
		return ERROR;
	}

	char x;
	int f=m;
	while(icin.good()){
		icin >> x;
		if(x == '1')
		{
			f=HT[f].rchild;
			if(HT[f].lchild==0 && HT[f].rchild==0)
			{
				icout << HT[f].pha;
				f=m;
			}
		}
		else if(x=='0')
		{
			f=HT[f].lchild;
			if(HT[f].lchild==0 && HT[f].rchild==0)
			{
				icout << HT[f].pha ;
				f=m;
			}
		}
	}
	icin.close();
	icout.close();
	cout << endl;
	return OK;
}

Status printfile(){
	ifstream icin("CodeFile");
	if(!icin.is_open())
	{
		cout << "�����ļ������ڣ�"<< endl;
		return ERROR;
	}
	ofstream icout("CodePrin");
	if(!icout.is_open())
	{
		cout << "���ļ�ʧ��"<< endl;
		return ERROR;
	}
	char x;
	int i=1;
	while(icin.good()){
		icin >> x;
		i++;
		if(i==50)
		{
			cout << endl;
			icout<< endl;
			i=1;
		}

		cout << x;
		icout << x;
	}
	cout << endl;
	return OK;
}

//�ð������ӡ��
void printHelp(HuffmanTree HT,int x,string ss,ofstream& icout)   
{  
    if( x==0 )     
        return;    
    ss+="   ";    
    printHelp(HT,HT[x].rchild,ss,icout);    
   	{HT[x].pha==' ' ? (cout<< ss<< HT[x].weight <<endl , icout<< ss<< HT[x].weight <<endl  ):  (cout<< ss<< HT[x].pha <<endl , icout<< ss<< HT[x].pha <<endl ) ;  }  
    printHelp(HT,HT[x].lchild,ss,icout);   
}  


Status Tree_printing(HuffmanTree HT,int n){
	if(HT==NULL)
	{
		return ERROR;
	}
	ofstream icout("TreePrint");

  //�������ӡ
    string ss="";    
    printHelp(HT,m,ss,icout);   
 
    icout.close();





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
				if( readhfmTree(HT,n)){
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
			if(Traslatecode(HT,n))
			{
				cout << "����ɹ�" << endl;
			}
			else
			{
				cout << "����ʧ��" << endl;
			}
		}else if (c=='P')
		{
			system("cls");
			
			if(printfile())
			{
				cout << "��ӡ�ɹ�!"<< endl;
			}
			else
			{
				cout << "��ӡʧ��!" << endl;
			}
		}
		else if(c=='T'){
			system("cls");
			if(Tree_printing(HT,n))
			{
				cout << "��ӡ�ɹ���";
			}
			else
			{
				cout << "��ӡʧ�ܣ���Ϊ��!";
			}
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
