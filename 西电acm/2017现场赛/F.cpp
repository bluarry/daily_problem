#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <stack>
#include <cmath>
using namespace std;
typedef long long ll;
vector<ll> ggcd;
ll ans=0;
ll x;
void getgcd(ll x){
	for(ll i=1;i<=sqrt(x);i++)
	{
		if(x%i==0) ggcd.push_back(i);
	}
}
void solve()
{
	ll len=ggcd.size();
	for(ll i=0;i<len;i++)
	{
			ll a=ggcd[i];
			ll cnt1=0;
			for(ll j=1;j<=a;j++)
			{
				if(a%j==0) cnt1++;
			}
			ll cnt2=0;
			for(ll k=1;k<=x/a;k++)
			{
				if((x/a)%k==0) cnt2++;
			}
			if(a!=x/a)
			ans+=cnt1*cnt2*2;
			else ans+=cnt1*cnt2;	
	}
}
int main()
{

	while(cin >> x)
	{	
		ggcd.clear();
		getgcd(x);
		int Ll=ggcd.size();
		ans=0;
		solve();
		cout << ans <<endl;
	}
	return 0;
}
