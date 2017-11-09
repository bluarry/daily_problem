#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main()
{
	// freopen("in.txt","r",stdin);
	int T;
	cin >> T;
	int cases=1;
	while(T--){
		
		int n,a,b;
		cin >> n >> a >>b;
		int x=gcd(a,b);
		cout << "Case #"<<cases++ <<": ";
		(n/x)&1 ? cout << "Yuwgna\n":cout << "Iaka\n";
	}
	return 0;
}
