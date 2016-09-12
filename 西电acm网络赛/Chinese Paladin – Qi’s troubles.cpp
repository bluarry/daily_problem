#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
#define mod 23333333333
typedef long long ll;

int main()
{
	ll n,m;
	while(cin >> n >> m)
	{
		ll _=m%3, _1=m/3,sum=0;
		sum =(sum +( ((_1*(_1-1)%mod)/2)%mod + ((_1*(_1+1)%mod)/2)%mod + ((_1*(2+_1+1)%mod)/2)%mod  ))%mod;
		while(_)
		{
			if(_==1)
			sum=(sum+_1)%mod;
			else if(_==2)
				sum=(sum+_1+1)%mod;
			_--;
		}
		sum =(sum+n*m%mod)%mod;
		cout << sum <<endl;
	}
	return 0;
}
