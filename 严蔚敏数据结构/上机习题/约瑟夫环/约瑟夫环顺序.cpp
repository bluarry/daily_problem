#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct LLnode{
	int data;
	int in;
};

int main()
{
	int m,n;

	LLnode x[100];
	cout << "������m�ĳ�ֵ: ";
	cin >> m;
	cout << "����������: ";
	cin >> n;
	cout << "����������ÿ������������ ��";
	for(int i=0;i<n;i++){
		cin >> x[i].data;
		x[i].in=1;
	}
	cout << "����˳��Ϊ: ";
	int j=1,k=1; //jΪ�߹��ڵ����ļ�������k��ʾ�Ѿ�����˶��ٽڵ�
	for(int i=0;k<=n;i=(i+1)%n)//i���Ʊ�����һֱ��ͷ��λ�ı�����֪�����еĽڵ����
	{
		if(x[i].in==0)	continue; //�����жϵ�ǰ�Ľڵ��Ƿ��Ѿ�����
		else j++;					//֮����û�г��У�������߹������ļ�������1
		if(j==m+1){					//������m+1;����Ϊ���жϵ����һλ��ʱ��j�����1
			x[i].in=0;				//Ԫ�س���
			m=x[i].data;			//����m
			cout << i+1 <<" ";		//����ڵ���
			j=1;					//���߹��ڵ����ļ�������Ϊ1
			k++;					//�Ѿ����е�Ԫ��+1
		}

	}
	return 0;
}
