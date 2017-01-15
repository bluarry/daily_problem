#include <iostream>
#include <algorithm>
using namespace std;
const int max_n=1000000+5;
int L,n;
int x[max_n];

void solve()
{
	int minT=0;
	for(int i=0;i<n;i++)
	{
		minT=max(minT,min(x[i],L-x[i]));
	}

	int  maxT=0;
	for(int i=0;i<n;i++)
		maxT=max(maxT,max(x[i],L-x[i]));

	cout << minT << " "<<maxT<<endl;
}
int main()
{
	int count;
	cin >> count;
	while(count--){
		cin >> L >> n;
		for(int i=0;i<n;i++)
		{
			cin >> x[i];
		}
		solve();
	}
}
/**
2
10 3
2 6 7
214 7
11 12 7 13 176 23 191
*/
