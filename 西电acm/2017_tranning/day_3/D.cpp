#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int R,C;
int m[100+5][100+5],dp[100+5][100+5];
int ans;

int dir_x[]={0,0,-1,1};
int dir_y[]={1,-1,0,0};
int dfs(int x,int y){
    if(dp[x][y]) return dp[x][y];
    int answ=0;
    for(int i=0;i<4;i++)
    {
        int xx=x+dir_x[i],yy=y+dir_y[i];
        if(xx>0 && xx<=R && yy>0 && yy <= C&& m[xx][yy] < m[x][y])
        {
            answ=max(answ,dfs(xx,yy));
        }
    }
    dp[x][y]=answ+1;
    return dp[x][y];
}



int main()
{
    //freopen("in.txt","r",stdin);
    while(cin >>R >> C){

    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++)
            cin >> m[i][j];


    int ans=0;
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++)
            ans=max(ans,dfs(i,j));
    cout << ans<<endl;


    }


    return 0;
}


