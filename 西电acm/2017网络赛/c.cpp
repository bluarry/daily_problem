#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	while(cin >> n){
		cout<< fixed << (ll)((0.5 * (n+1) * n)+1) << endl;

	}
	return 0;
}