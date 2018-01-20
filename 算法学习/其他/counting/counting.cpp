#include <iostream>
using namespace std;
typedef long long ll;
// 数字
ll pow[20];
int getn(ll num){
	ll x=num;
	if(x==0) return 1;
	int i=0;
	while(x){
		x/=10;
		i++;
	}
	return i;
}
ll countzeronum(ll num,int n){
	int cur=n;
	int high=0;
	int low=num%pow[cur-1];
	ll sum=0;
	for(cur =n;cur>=1;cur--){
		int a=num/pow[cur-1] %10;
		low=num%pow[cur-1];
		high=num/pow[cur];
		if(a==0){
			sum+=(high-1)*pow[cur-1]+low+1;
		}else if(a>0){
			sum+=(high)*pow[cur-1];
		}		
	}
	return sum;
}
ll  mycount(ll num,int n,int x){
	int cur=n;
	int high=0;
	int low=num%pow[cur-1];
	ll sum=0;
	for(cur =n;cur>=1;cur--){
		int a=num/pow[cur-1] %10;
		low=num%pow[cur-1];
		high=num/pow[cur];
		if(a==x){
			sum+=high*pow[cur-1]+low+1;
		}else if(a>x){
			sum+=(high+1)*pow[cur-1];
		}else if(a<x){
			sum+=high*pow[cur-1];
		}
//		cout << "a = "<< a<<" high = " << high << " low= " << low  << " sum= " << sum <<endl;			
	}
	return sum;
}
int main()
{
	pow[0]=1;
	for(int i=1;i<20;i++) pow[i]=pow[i-1]*10;
	ll num;
	int n;
	while(cin >> num){
		n=getn(num);
		cout << countzeronum(num,n)<<endl;
		
		for(int i=1;i<=9;i++)
			cout << mycount(num,n,i) << endl;



	}




	return 0;
}
