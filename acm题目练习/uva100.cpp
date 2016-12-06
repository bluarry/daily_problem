#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int findmax(int x)
{
	int sum=1;
	while(x!=1)
	{
		if(x%2==1) //奇数
		{
			x=x*3+1;
		}
		else
		{
			x/=2;
		}

		sum++;
	}
	return sum;
}


int f(int x,int y)
{
	int ma=0;
	for(int i=min(x,y);i<=max(x,y);i++)	//注意，这里必须是从小到大，但是ｘ可能小于ｙ，所以调用max和min函数
	{
		int temp=findmax(i);
		if( temp > ma)
		{
			ma=temp;
		}
	}
	return ma;
}


int main()
{
	int i,j;
	while(cin >> i >> j)
	{
		int ma=f(i,j);
		 cout << i << " " << j << " " << ma<<endl;
	}
	return 0;
}
