#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <stack>
using namespace std;


typedef long long ll;

int main()
{
	//freopen("in.txt","r",stdin);
	ll n;
	while(cin >> n){
		if(n>=0&&n<=1000) cout << "XiaoZhen"<<endl;
		else if(n>1000&&n<10000) cout << "Zh0ngshen"<<endl;
		else if(n>=10000) cout << "DaNuo"<<endl;	
	}
	return 0;
}
