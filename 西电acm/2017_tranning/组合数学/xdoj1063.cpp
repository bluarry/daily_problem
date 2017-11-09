#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;

ll quick_pow(ll a,ll b){
	ll ans=1;
	a=a%MOD;
	while(b){
		if(b&1) ans=(ans*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return ans;
}

int main()
{
	int n;
	while(cin >> n){
		if(n%2)
			cout << quick_pow(2,n-1) << endl;
		else 
		{
			cout << ((quick_pow(2,n-1)+quick_pow(2,n/2-1))%MOD)<< endl;
		}
	}
	return 0;
}
