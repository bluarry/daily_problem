#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int Max=10;
typedef long long ll;
ll n,a,b,L,R;
std::vector<char> s,t;

void getsstring(){
	int w[n+5];
	w[0]=b;
	s.clear();
	if(a!=1){
	
	for(int i=1;i<n;i++)
		w[i]=(w[i-1]+a)%n;
	for(int i=0;i<n;i++)
	{
		if( (w[i]>=L&&w[i]<=R) && w[i]%2==0 )
			s.push_back('A');
		else if( (w[i]>=L&&w[i]<=R) && w[i]%2==1 )
			s.push_back('T');
		else if( (w[i]<L || w[i]>R) && w[i]%2==0 )
			s.push_back('G');
		else if( (w[i]<L || w[i]>R) && w[i]%2==1)
			s.push_back('C');
	}
}
else {


	
}
	t.clear();
	char c;
	while(cin >> c)
	{
		t.push_back(c);
	}


}

void getnext(int next[])
{
	int i,j;
	j=next[0]=-1;
	i=0;
	while(i < t.size())
	{
		while(-1!=j && t[i]!=t[j])j=next[j];
		next[++i]=++j;
	}
}	




ll kmp()
{
	//在s中找t的个数, s主串，t模式串
	int next[t.size()+5];
	ll ans=0;
	getnext(next);
	int i=0,j=0;
	while(i<s.size())
	{
		while(-1!= j && s[i]!=t[j])j=next[j];
		i++;j++;
		if(j>=t.size()){
			ans++;
			j=next[j];
		}
	}
	return ans;
}

int main()
{
	//freopen("in.txt","r",stdin);
	cin >> n>>a >> b >> L>>R;

	getsstring();

	ll res=kmp();
	cout <<res <<endl;

	return 0;
}
