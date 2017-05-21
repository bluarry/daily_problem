#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int Max=10;
typedef long long ll;
ll n,a,b,L,R;
std::vector<char> s,t;

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
	int n=s.size(),m=t.size();
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






	return 0;
}