#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll maxn=100000+10;
ll n,k;
ll C[maxn];
ll lowbit(ll x) {return x & (-x);}

ll query(ll i)
{
	ll sum=0;
	while(i>0){sum+=C[i];i-=lowbit(i);}
	return sum;
}
ll update(ll i,ll x)
{
	while(i<=n){
		C[i]+=x;
		i+=lowbit(i);
	}
}
struct xxxxx
{
	ll v,index;
	bool operator < (const xxxxx & aa)const{
		if(v!=aa.v)return v < aa.v;
		return index<aa.index;
		}
}a[maxn];


int main()
{
//	 freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(cin>> n >> k)
	{
		memset(C,0,sizeof(C));
		for(ll i=1;i<=n;i++)
		{
			cin>> a[i].v;
			a[i].index=i;
		}
		sort(a+1,a+1+n);
		ll ans=0;
		for(ll i=1;i<=n;i++)
		{
			ll x=a[i].index;
			update(x,1);
			ll s=query(x);
			ans+=i-s;
		}
		cout << max(0ll,ans-k) << endl;
	}
		return 0;
}
