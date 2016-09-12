#include <iostream>
#include <cstdio>
using namespace std;



int judge(int x,int y)
{

	int bb[10]={0};
	if(y>98765) return 0;
	if(x<10000)bb[0]=1;
	while(x)
	{	
		bb[x%10]=1;
		x/=10;
	}
	while(y)
	{	
		bb[y%10]=1;
		y/=10;
	}

	int sum=0;
	for(int i=0;i<=9;i++)
		sum += bb[i];
	return (sum==10);
}
int main()
{
	#ifdef LOCAL
	freopen("D:\\1.in","r",stdin);
	#endif
	int n;
	int flag=0;
	int T=0;
	while(cin >> n && n)
	{
	flag=0;
	if(T++) cout << endl;
	for(int i=1234;i<98766;i++)
		if(judge(i,i*n))
		{
			 i>10000? (cout << n*i << " / " << i <<" = " << n << endl) : (cout << n*i << " / 0" << i <<" = " << n << endl);
			flag=1;	
		}
		if(!flag)
		{
			cout << "There are no solutions for "<<n<<"."<< endl;
		}
	}
	return 0;
}

