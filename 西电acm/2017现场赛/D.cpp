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
ll n,m,p;
ll C(int n,int m){
	ll fenzi=1;
	for(ll i=0;i<m;i++)
		fenzi=(fenzi*(n-i))%p;
	ll fenmu=1;
	for(ll i=1;i<=m;i++)
		fenmu=(fenmu*i)%p;
	
	return fenzi/fenmu;
}


int main()
{
	while(cin >> n >> m )
	{
		cout << C(n,m) <<endl;
		
		
		
	}
	
	
	
	
	
	
	
	
	
	
	return 0;
}
