#include<bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll ;

const int mod = 1e9 + 7 ;

ll powmod( ll a, ll b )
{
	ll res = 1; if ( a >= mod )
		a %= mod;
	for (; b; b >>= 1 )
	{
		if ( b & 1 )
			res = res * a;
		if ( res >= mod )
			res %= mod;
		a = a * a;
		if ( a >= mod )a %= mod;
	}
	return(res);
}

const int maxn = 100010;
const int inf = INT_MAX;

bool p[1000000 + 5];
vector<ll> prime;

ll f(ll a, ll b, ll n)
{
	ll ret = 1;
	while(1) {
		ret = ret * n;
		if( (a - 1) / ret * ret + ret > b)
			break;
	}
	ret = ret / n;
	return ret;
}
int main() {
	ll n, k;
	cin >> n >> k;
	for(int i = 2; i <= 1000; i++) {
		if(p[i])
			continue;
		for(int j = i * i; j <= 1000000; j += i)
			p[j] = 1;
	}
	for(int i = 2; i <= 1000000; i++)
		if(p[i] == 0)
			prime.pb(i);
	ll ans = powmod(n + 1, mod - 2);
	for(int i = 0; i < prime.size(); i++) {
		ans = ans * f(n + 1 - k, n + 1, prime[i]);
		if(ans >= mod)
			ans %= mod;
	}
	cout << ans << endl;
    return 0;
}

