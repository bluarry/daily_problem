#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;

typedef long long ll;
const int maxn=200000+5;
ll h[maxn];
ll n,le;

int lowbit(int x)
{
	return (x & (-x));
}

void modify(int x,ll add,ll n){
	while(x<= n)
	{
		h[x]+=add;
		x+=lowbit(x);
	}
}
ll get_sum(int x){
	ll ret=0;
	while(x > 0)
	{
		ret+=h[x];
		x-=lowbit(x);
	}
	return ret;
}


ll solve()
{
	ll realmin=999999999999;
	h[0]=0;

	for(int i=0;i<=n-le;i++)
	{
		 ll mmin=get_sum(i+le)-get_sum(i);
		 realmin=min(mmin,realmin);
	}


	return realmin;
}


int main()
{

	while(cin >> n >> le){
		memset(h,0,sizeof(h));
		for(int i=1;i<= n;i++)
			{
				ll x;
				cin >>x;
				modify(i,x,n);
			}
		cout << solve()<<endl ;
	}


	return 0;
}
