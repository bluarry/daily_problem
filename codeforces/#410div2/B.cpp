#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=50;
const int INF=99999999;
string s[maxn];
int next[maxn*2+5];
int n;
void getnext(int x)
{
	memset(next,0,sizeof(next));
	next[0]=-1;
	int i=0,j=-1;
	while(i < s[x].length())
	{
		if(j==-1 || s[x][i]==s[x][j])
		{
			i++,j++;
			if(s[x][i]!=s[x][j]) next[i]=j;
			else next[i]=next[j];
		}
		else j=next[j];
	}

}
int kmp(string &a,string &b){
	int i=0,j=0;
	while(i<a.length() && j<b.length())
	{
		if(a[i]==b[j]||j==-1)i++,j++;  
        else j = next[j];  
	}
	if(j==b.length())return i-b.length()+1;  
    else return -1;  

}


int cmp(int x,const string ss)
{
	int times=0;
	for(int i=0;i<n && i!=x ;i++)
	{
		getnext(i);
		string tmp= s[x] + s[x];
		int index=kmp(tmp,s[i]);
		times+=index+1;
	}

	return times;
}
int main()
{
	int cnt=INF;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> s[i];

	for(int i=0;i<n;i++)
		cnt=min(cmp(i,s[i]),cnt);

	cout << cnt ;


	return 0;
}