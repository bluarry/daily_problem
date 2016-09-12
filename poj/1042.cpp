#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n; //声明湖的个数
int fi[30]; //每一个湖钓的初始鱼数
int cfi[30];
int di[30];
int ti[30];
int h;

struct node
{
	int max;  //枚举在每个湖钓到的最大的鱼数
	int num[30];
}lake[30];

int getmax(int p[],int i,int j){
	int x=p[i],y=i;
	for(int ii=i+1;ii<=j;ii++){
		if(x<p[ii])
		{
			x=p[ii];
			y=ii;
		}
	}
	return y;
}



void solve(){
	//大概思路，贪心算法
	//枚举结束的位置，从第一个湖走到当前枚举的湖，只要贪心的每次在鱼数最大的湖里钓即可

	int T=h*60,t,CT;
	for(int i=1;i<=n;i++)
	{
		lake[i].max=0;
		for(int j=1;j<=n;j++)
			lake[i].num[j]=0;
	}

	for(int i=1;i<=n;i++)
	{
		CT=T;
		t=0;
		for(int j=1;j<=i;j++)
		{
			cfi[j]=fi[j];
			CT= (j<i) ? CT-ti[j]*5 : CT ;  
		}

		while(t<CT){
			int k=getmax(cfi,1,i);
			lake[i].max+=cfi[k];
			lake[i].num[k]+=5;
			cfi[k] > di[k] ? cfi[k]-=di[k] :  cfi[k]=0;
			t+=5;
		}
	}


	for(int i=1;i<=n;i++)
		cfi[i]=lake[i].max;

	int k=getmax(cfi,1,n);

	for(int i=1; i<=n;i++)
		i==n ? cout << lake[k].num[i] <<endl : cout << lake[k].num[i] << ", ";
	cout << "Number of fish expected: " << lake[k].max<< "\n\n";
}
int main()
{
	//freopen("D:\\1.in","r",stdin);
	while(cin >> n){
		if(!n) break;
		cin >> h;
		for(int i=1;i<=n;i++)
			cin >> fi[i];
		for(int i=1;i<=n;i++) 
			cin >> di[i];
		for(int i=1;i<n;i++)
			cin >> ti[i];

		solve();
	}
	return 0;
}
