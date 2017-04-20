#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;

typedef long long ll;
const int maxn=200000+5;
ll h[maxn];
ll n,le;


ll solve()
{
	ll realmin,mmin=0;
	for(int i=0;i<le;i++)
	{
		mmin+=h[i];
	}
	realmin=mmin;

	for(int i=1;i<=n-le;i++)
	{
		mmin-=h[i-1];
		mmin+=h[i+le-1];
		realmin=min(realmin,mmin);
	}
	return realmin;
}


int main()
{

	while(cin >> n >> le){
		memset(h,0,sizeof(h));
		for(int i=0;i< n;i++)
			{
				cin >> h[i];
			}
		cout << solve()<<endl ;
	}


	return 0;
}
