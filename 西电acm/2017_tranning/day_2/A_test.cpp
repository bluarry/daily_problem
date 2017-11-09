#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1000;

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
	int n;
	cin >> n;
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
	cout << ans << endl;
	return 0;

}
