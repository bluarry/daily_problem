//sort以及lower_bound的应用
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn=10000;

int main()
{
	freopen("D:\\1.in","r",stdin);
	int n,q,x,a[maxn],kase=0;
	while(cin >>n>>q)
	{
		if(n==0) break;
		cout << "CASE# "<< ++kase <<":"<< endl;
		for(int i=0;i<n;i++)
			cin >> a[i];

		sort(a,a+n);
		while(q--)
		{
			cin >> x;
			int p=lower_bound(a,a+n,x)-a;
			if(a[p]==x) cout << x << " found at "<<p+1<<endl;
			else
				cout << x << " not found" << endl;

		}

	}
	return 0;
}
