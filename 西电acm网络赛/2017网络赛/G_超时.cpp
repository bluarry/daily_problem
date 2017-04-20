#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stdio.h>
using namespace std;

typedef long long ll;
const int maxn=200000+5;
ll h[maxn];

int main()
{

	ll n,le;
	while(cin >> n >> le){
		for(int i=0;i< n;i++)
			cin >> h[i];
				
	ll realmin=999999999999;
	for(int i=0;i<n-le;i++)
	{
		ll mmin=0;
		for(int j=i;j<=i+le;j++)
		{
			mmin+=h[i];
			if(mmin > realmin) break;
		}
		if(mmin < realmin) realmin=mmin;
	}
	cout << realmin<<endl;



	}


	return 0;
}
