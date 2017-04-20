#include <map>
#include <set>
#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;

typedef long long ll;

const ll q = 2147483647,a=3;

ll exp(ll aa,ll b){
  ll t,y;
  t=1; y=aa;
  while (b!=0){
    if (b&1==1) t=t*y%q;
    y=y*y%q; 
	b=b>>1;
  }
  return t;
}

ll ff(ll ya)
{
	ll te=0,xa=0;
	for(int k=0;xa< q;k++)
	{
		te=ya+k*q;
		xa=(ll)(log(te)/log(3));
		if(exp(3,xa)==ya) return k;
	}

	return -1;
}

int main()
{
	freopen("in.txt","r",stdin);
	
	ll xb=-1,yb,xa=-1,ya;
	while(cin >> ya >> yb)
	{
		xa=xb=-1;
		xa=ff(ya);
		xb=ff(yb);
		if(xa!=-1)
		{
			cout << exp(yb,xa) << endl;
		}
		else if(xb!=-1){
			cout << exp(ya,xb) << endl;
		}
		else 
		{
			cout << "No Solution"<<endl;
		}

	}

	return 0;
}
