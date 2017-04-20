#include <map>
#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=10,q=2147483647,a=3;
typedef long long ll;
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
	ll xa;
	if((q-2-ya)%3==0)
	xa =q-2 - (ll)((q-2-ya)/3) ;
	else xa=-1;
	
	return xa;
}

//欧拉函数，求小于等于n的与n互质的因数个数
int Euler(int n)  
{  
    int ret=n,i;  
    for(i=2;i<=sqrt(n);i++)  
     if(n%i==0)  
      {  
        ret=ret/i*(i-1);//先进行除法防止溢出   
        while(n%i==0)  
          n/=i;  
     }  
    if(n>1)  
          ret=ret/n*(n-1);  
        return ret;  
}  
int main()
{
	//freopen("out.txt","w",stdout);
ll xb=-1,yb,xa=-1,ya;
	while(cin >> ya >> yb)
	{
		xa=xb=-1;
		xa=ff(ya);
		xb==ff(yb);
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
