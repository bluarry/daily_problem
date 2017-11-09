#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=100000+5;

int C[maxn];
int lowbit(int x) {return x&(-x);}

int query(int i)
{
	int sum=0;
	while(i>0){sum+=C[i];i-=lowbit(i);}
	return sum;
}
int update(int i,int x)
{	
	while(i<maxn){
		C[i]+=x;
		i+=lowbit(i);
	}
}
struct xxxxx
{
	int v,index;
	bool operator < (const xxxxx & aa)const{return v < aa.v;}
}a[maxn];


int main()
{
	 // freopen("in.txt","r",stdin);
	int n,k;
	while(cin >> n>>k)
	{
		memset(C,0,sizeof(C));
		for(int i=1;i<=n;i++)
		{
			cin >> a[i].v;
			a[i].index=i;
		}
		sort(a+1,a+1+n);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int x=a[i].index;
			update(x,1);
			int s=query(x);
			ans+=i-s;
		}
		ans-=k;
		if(ans<0) ans=0;
		cout << ans << endl;
	}
		return 0;
}
