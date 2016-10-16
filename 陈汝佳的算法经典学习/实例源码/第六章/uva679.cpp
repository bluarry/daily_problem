//#define LOCAL
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 100000+5




int main()
{
	#ifdef LOCAL
	freopen("D:\\1.in","r",stdin);
	//freopen("D:\\1.out","w",stdout);
	#endif

		int n;
		cin >>n;
		int B[n];
		int i;
		for(i=0;i<n;i++)
		{
			cin >> B[i];
		}

		if(B[i-1]-B[i-2]>0)
			cout << "UP"<<endl;
		else if(B[i-1]-B[i-2]<0)
			cout << "DOWN"<<endl;












	return 0;
}

/*
<string>-v kext-dev-mode=1 rootless=0 darkwake=0 dart=0</string>
*/
