#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main()
{
	ll n;

	cin >> n;

	ll status[n+1][6];

	memset(status,0,sizeof(status));

	for(ll i=1;i<=n;i++)
	{
		status[i][0] = 1;
		status[i][1] = (status[i-1][0]+status[i-1][1]*2)%mod;
		status[i][2] = (status[i-1][0]+status[i-1][2])%mod;
		status[i][3] = (status[i-1][1]+status[i-1][3]*2)%mod;
		status[i][4] = (status[i-1][1]+status[i-1][2]+status[i-1][4]*2)%mod;
		status[i][5] = (status[i-1][5]*2+status[i-1][3]+status[i-1][4])%mod;
         
	}
	cout << status[n][5]<<endl;
	return 0;
}
