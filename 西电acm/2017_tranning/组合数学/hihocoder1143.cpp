#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
//矩阵快速幂求斐波那契数列
typedef long long ll;
const ll MOD=19999997;
ll N[2][2],ans[2][2],tmp[2][2],E[][2]={{1,0},{0,1}};

void Martix_multipy(ll a[][2],ll b[][2],ll c[][2]){
	for(ll i=0;i<2;i++) for(ll j=0;j<2;j++) c[i][j]=0;

	for(ll i=0;i<2;i++)
		for(ll k=0;k<2;k++)
			for(ll j=0;j<2;j++)
				c[i][j]=( c[i][j]+ (a[i][k]*b[k][j])%MOD )%MOD;
}
void setv(ll a[][2],ll b[][2]){
	for(ll i=0;i<2;i++)
		for(ll j=0;j<2;j++)
			a[i][j]=b[i][j];
}
void prll(ll a[][2]){
	for(ll i=0;i<2;i++)
		for(ll j=0;j<2;j++)
			j!=1? cout << a[i][j]<< " ":cout << a[i][j]<<endl;
}
void Martix_quickpow(ll N[][2],ll t)
{
	setv(ans,E);
	while(t){
		if(t&1){
			Martix_multipy(ans,N,tmp);
			setv(ans,tmp);
		}
		Martix_multipy(N,N,tmp);
		setv(N,tmp);
		t>>=1;
	}
}


void solve(ll n)
{
	N[0][0]=0;N[0][1]=1;
	N[1][0]=1;N[1][1]=1;
	Martix_quickpow(N,n);
	cout <<  ans[1][1] <<endl;
}

int main()
{
	// freopen("in.txt","r",stdin);
	ll n;

	while(cin >> n){
		solve(n);
	}

	return 0;
}
