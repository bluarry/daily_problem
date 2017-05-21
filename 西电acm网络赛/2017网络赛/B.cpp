#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

char cmap[51][51];
int imap[51][51];
int n,m;

bool iinput(){
	string s;
	cin >> s;
	if(s.length() <=0) return false;
	for(int i=0;i<s.length();i++)
	{
		cmap[0][i]=s[i];

	}
	m=s.length();
	int i=1;
	for(;cin >> cmap[i];i++);
	n=i;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(cmap[i][j]=='*') imap[i][j]=1;
		}
	}

	return true;
}


int dir_x[]={1,0,-1,0};
int dir_y[]={0,1,0,-1};

void dfs(int x,int y)
{
	if(x <0 || x>=n) return;
	if(y<0 || y>=m) return;
	if(imap[x][y]==0) return;

	if(imap[x][y]==1)
	imap[x][y]=0;

	for(int i=0;i<4;i++)
	{
		int xx=x+dir_x[i];
		int yy=y+dir_y[i];
		dfs(xx,yy);
	}
	
}


int main()
{
	//freopen(".\\in.txt","r",stdin);
	memset(cmap,0,sizeof(cmap));
	memset(imap,0,sizeof(imap));
	iinput();

	for(int i=0;i<m;i++)
		if(imap[0][i]) dfs(0,i);
		else if(imap[n-1][i]) dfs(n-1,i);
	for(int i=0;i<n;i++)
		if(imap[i][0]) dfs(i,0);
		else if(imap[i][m-1])dfs(i,m-1);

	int result=0;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			result+=imap[i][j];

		cout << result << endl;
	return 0;
}
