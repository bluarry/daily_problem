#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
const ll INF=0x7fffffffffffffffll;
ll n,ans;
int meiju(ll x){
	if(x<2) return 0;
	ll t=x;
	for(ll i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			if(x%(i*i)==0) return 0;
			x/=i;
		}
	}
	ans=min(ans,abs(t*t-n));
	return 1;
}
int main()
{
	// freopen("in.txt","r",stdin);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		ll x=(ll)(sqrt(n)+0.5);
		int flag=0;
		ans=INF;
		for(int i=0;;i++)
		{
			if(meiju(x+i)) flag=1;
			if(meiju(x-i)) flag=1;
			if(flag==1) break;
		}
		cout << ans<<endl;
	}
	return 0;
}
