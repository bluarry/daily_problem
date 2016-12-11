#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn=3000+5;
int seq[maxn];
int cha[maxn];
int main()
{
	// int se[maxn];
	int n;
	while(cin >> n)
	{
		memset(cha,0,sizeof(cha));
		int m=n;
		while(m--) cin >>seq[n-m-1];
		for(int i=0;i<n-1;i++)
		{
			int ccha=seq[i]-seq[i+1];
			if(ccha < 0)	cha[-ccha]++;
			else cha[ccha]++;
		}
		int flag=1;
		for(int i=1;i<n;i++)
		{
			if(!cha[i]) flag=0;
		}
		if(flag) cout << "Jolly"<<endl;
		else cout << "Not jolly"<<endl;
	}

	return 0;
}
