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
	cout << "请输入m的初值: ";
	cin >> m;
	cout << "请输入人数: ";
	cin >> n;
	cout << "请依次输入每个人所持密码 ：";
	for(int i=0;i<n;i++){
		cin >> x[i].data;
		x[i].in=1;
	}
	cout << "出列顺序为: ";
	int j=1,k=1; //j为走过节点数的计数器，k表示已经输出了多少节点
	for(int i=0;k<=n;i=(i+1)%n)//i控制遍历，一直从头到位的遍历，知道所有的节点出列
	{
		if(x[i].in==0)	continue; //首先判断当前的节点是否已经出列
		else j++;					//之后，若没有出列，则计算走过次数的计数器加1
		if(j==m+1){					//这里是m+1;是因为当判断到最后一位的时候，j多加了1
			x[i].in=0;				//元素出列
			m=x[i].data;			//更新m
			cout << i+1 <<" ";		//输出节点编号
			j=1;					//将走过节点数的计数器置为1
			k++;					//已经出列的元素+1
		}

	}
	return 0;
}
