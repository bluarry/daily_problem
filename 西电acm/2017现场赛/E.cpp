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
using namespace std;
const int M=2097151;
typedef long long ll;
long long pow_m(long long a,long long n)
{
	long long ret = 1;
	long long tmp = a%M;
	while(n)
	{
	if(n&1)ret = (ret*tmp)%M;
	tmp = tmp*tmp%M;
	n >>= 1;
	}
		return ret;
}

int main()
{
	ll n;
	while(cin >> n){
		cout << ((pow_m(2,n)-1)*2)%M <<endl;
		}
	return 0;
}
