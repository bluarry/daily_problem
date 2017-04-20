#include <iostream>
#include <set>
#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;

typedef int States[9];
const int maxn=1000000;
States st[maxn],goal; //st为数组模拟队列
set<int > vis;
int dist[maxn];
int fa[maxn];
const int dir_x[]={1,-1,0,0};
const int dir_y[]={0,0,1,-1};
//最慢
int try_to_insert(int s){
	int code=0;
	for(int i=0;i<9;i++) code=code*10+st[s][i];
	if(vis.count(code)) return 0;
	vis.insert(code);	
	return 1;
}
void init_lookup_table()
{
	vis.clear();
}
// 效率优化1(中等)
int viss[362880],fact[9];
void init_lookup_table1()
{
	fact[0]=1;
	for(int i=1;i<9;i++)
	{
		fact[i]=fact[i-1]*i;
	}
}
int try_to_insert1(int s)
{
	int code=0;
	for(int i=0;i<9;i++)
	{
		int cnt=0;
		for(int j=i+1;j<9;j++) if(st[s][j] < st[s][i]) cnt++;
		code +=fact[8-i]*cnt;
	}
	if(viss[code]) return 0;
	return viss[code]=1;
}
//哈希优化(最快)
const int hashsize=1000003;
int head[hashsize],next[maxn];
void init_lookup_table2()
{
	memset(head,0,sizeof(head));
	memset(next,0,sizeof(next));
}
int hash(States &s)
{
	int v=0;
	for(int i=0;i<9;i++) v=v*10+s[i];
	return (v % hashsize);
}

int try_to_insert2(int s)
{
	int h=hash(st[s]);
	int u=head[h];
	while(u){
		if(memcmp(st[u],st[s],sizeof(st[u]))==0) return 0;
		u=next[u];
	}
	next[s]=head[h];
	head[h]=s;
	return 1;
}

int bfs()
{
	init_lookup_table2();
	memset(dist,0,sizeof(dist));
	int front=1,rear=2;
	while(front< rear)
	{
		States &s=st[front];
		if(memcmp(goal,s,sizeof(s))==0){
			return front;
		}

		int z;
		for(z=0;z<9;z++) if(!s[z]) break;
		int x=z/3,y=z%3;
		for(int i=0;i<4;i++)
		{
			int newx=x+dir_x[i],newy=y+dir_y[i];
			int newz=newx*3+newy;
			if(newx >=0 && newx <3 && newy >=0 && newy <3)
			{
				States &r=st[rear];
				memcpy(r,s,sizeof(s));
				r[newz]=s[z];
				r[z]=s[newz];
				dist[rear]=dist[front]+1;
				if(try_to_insert2(rear)) fa[rear++]=front;
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
	int start=clock();
	int ans=bfs();
	if(ans>0)
	{
		cout << dist[ans] << endl;
	}
	else{
		cout << "-1" << endl;
	}
	int end=clock();


	while(ans){
		for(int i=0;i<9;i++) (i+1)%3 ? cout << st[ans][i] << " ":cout << st[ans][i] <<endl;
			ans=fa[ans];
		cout << "\n"<<endl;
	}

	cout << "\n\nThe Whole runing time is " << end-start << " ms" ;


	return 0;
}
