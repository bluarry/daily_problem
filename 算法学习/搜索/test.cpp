#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
typedef int States[9];
const int maxnstates=1000000;
States st[maxnstates],goal;
int dist[maxnstates];

const int dir_x[]={-1,1,0,0};
const int dir_y[]={0,0,1,-1};

set<int>vis;
void init_lookup_table(){vis.clear();}
int try_to_insert(int s){
	int v=0;
	for(int i=0;i<=9;i++) v=v*10+st[s][i];
	if(vis.count(v)) return 0;
	vis.insert(v);
	return 1;
}

int bfs()
{
	init_lookup_table();
	int front=1,rear=2;
	while(front < rear)
	{
		States &s=st[front];
		if(memcmp(goal,s,sizeof(s))==0){
			return front;
		}
		int pp;
		for(pp=0;pp<9;pp++)if(!s[pp])break;

		int x=pp/3,y=pp%3;
		for(int i=0;i<4;i++)
		{
			int newx=x+dir_x[i],newy=y+dir_y[i];
			int newz=newx*3+newy;
			if(newx >=0 && newx <3 && newy >=0 && newy <3)
			{
				States &t=st[rear];
				memcpy(&t,&s,sizeof(s));
				t[newz]=s[pp];
				t[pp]=s[newz];
				dist[rear]=dist[front]+1;

				if(try_to_insert(rear))rear++;
			}

		}

	front++;
	}
	return 0;
}



int main()
{
	freopen("in","r",stdin);
	for(int i=0;i<9;i++) cin >> st[1][i];
	for(int i=0;i<9;i++) cin >> goal[i];
	int ans=bfs();
	if(ans > 0) cout << dist[ans] << endl;
	else
		cout << "-1" << endl;
	return 0;
}
