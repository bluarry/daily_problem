#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

typedef long long ll;

struct actime
{
	ll start,end;
	bool operator < (const actime &x){
		return end<x.end;
	}
};

bool cmp1(actime a,actime b)
{
	return a.end<b.end;
}
bool cmp2(actime a,actime b)
{
	return a.end<b.end;
}
int main()
{
	ll n;
	cin>> n;
	actime a[n+1],b[n+1],c[n+1];
	for(int i=0;i<n;i++)
	{
		cin >> a[i].start >> a[i].end;
	}
	sort(a,a+n,cmp1);
	ll co=0,j=-10e9;
	for(int i=0;i<n;i++)
	{	
		if(j<a[i].start)
		{
			j=a[i].end;
			co++;
		}
	}
	cout << co << endl;
	return 0;
}
