#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#include <cstdlib>
using namespace std;

const int maxn=1000+10;


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	freopen("D:\\1.in","r",stdin);
	int t,kcase=0;
	while(cin >> t)
	{
		if(!t) break;
		cout << "Scenario #"<< ++kcase <<endl;

		map<int,int> team;
		for(int i=0;i<t;i++){
			int n,x;
			cin >> n;
			while(n--) {cin >> x;team[x]=i;}
		}

		queue<int> q,q2[maxn];
		while(1){
			int x;
			char cmd[10];
			cin >> cmd;
			if(cmd[0]=='S') break;
			else if(cmd[0]=='D')
			{
				int t=q.front();
				cout << q2[t].front()<<endl;
				q2[t].pop();
				if(q2[t].empty()) q.pop();
			}
			else if(cmd[0]=='E')
			{	
				cin >> x;
				int t=team[x];
				if(q2[t].empty())q.push(t);
				q2[t].push(x);
			}
		}
		cout << endl;
	}
	return 0;
}
