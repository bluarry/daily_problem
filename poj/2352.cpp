#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=32000+10;
int N;
int data[maxn];
int level[maxn];

int lowbit(int x)
{
	return x&(-x);
}
void add(int i,int x)
{
	for(int j=i;j<maxn;j+=lowbit(j))
		data[j]+=x;
}
int chaxun(int x)
{
	int sum =0;
	for(int i=x;i>0;i-=lowbit(i))
		sum+=data[i];
	return sum;
}



int main()
{
	ios::sync_with_stdio(false);
	
	while(cin >> N)
	{
		memset(level,0,sizeof(level));
		memset(data,0,sizeof(data));
		int X,Y;
		for(int i=0;i<N;i++)
		{
			cin >> X >> Y;
			level[chaxun(X+1)]++; //X可能为0,而data是从下标1开始的，故加1
			add(X+1,1);
		}
		for(int i=0;i<N;i++)
			cout << level[i] << endl;
	}
	return 0;
}
