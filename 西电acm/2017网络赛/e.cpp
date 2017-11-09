#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

// n(n+1)(2n+1)/6
int main()
{
	ll n,p;
	while(cin >> n >> p){
		printf("%lld\n",  (( (n%p) * ((n+1)%p) * ((2*n+1)%p) ) /6)%p );

	}

	return 0;
}
