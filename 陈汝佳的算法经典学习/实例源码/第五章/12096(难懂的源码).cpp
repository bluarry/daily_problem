#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef set<int> Set;
map<Set,int> IDcache;
vector<Set> Setcache;

int ID(Set x)
{	
	if(IDcache.count(x)) return IDcache[x];
	Setcache.push_back(x);
	return IDcache[x]=Setcache.size()-1;
}
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())


int main()
{
	//freopen("D:\\1.in","r",stdin);
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	stack<int> s;
	int T;
	cin >> T;
	while(T--){
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		string op;
		cin >> op;
		if(op[0]=='P') s.push(ID(Set () ));
		else if(op[0]=='D') s.push(s.top());
		else
		{
			Set x1=Setcache[s.top()];s.pop();
			Set x2=Setcache[s.top()];s.pop();
			Set x;
			if(op[0]=='U') set_union(ALL(x1),ALL(x2),INS(x));
			if(op[0]=='I') set_intersection(ALL(x1),ALL(x2),INS(x));
			if(op[0]=='A') {x=x2;x.insert(ID(x1));}
			s.push(ID(x));
		}
		cout << Setcache[s.top()].size() << endl;
	}
	cout << "***" << endl;
}



}
