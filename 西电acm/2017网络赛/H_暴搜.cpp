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

int a,b,s,t,c,d;


bool dfs(int na,int nb,int times)
{
	if(na<0 || nb <0) {return false;}
	if( !(na||nb) )
	{
		if((times)%2)
			return true;
		else 
			return false;
	}
	bool ll=false;
	for(int s=1;s<=c;s++){
		if(ll) break;
		for(int t=1;t<=d;t++)
		{
			ll=dfs(na-s,nb,times+1);
		 ll= ll==true?ll:dfs(na,nb-t,times+1);
		if(ll) break;
		}
	}
	return ll;
}

int main()
{
	while(cin >> a >> b >> c >> d)
	{
		if(dfs(a,b,0))
		{
			cout << "NUO!"<<endl;
		}
		else 
		{
			cout << "NO!" << endl;
		}


	}
	return 0;
}
