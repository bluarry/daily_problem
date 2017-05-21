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

typedef long long ll;
const ll M=140105200078888888;
int main()
{
	ll n;
	while(cin >> n){
		if(n==0)cout << 1<<endl;
		else{
			ll t=(n*(n-1)%M+2)%M;
			cout << t << endl;
		}
	}
	return 0;
}
