#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=100;
char pic[maxn][maxn];
int flag[maxn][maxn];
int m,n;

void dfs(int i,int j,int id)
{
    if(i<0 || j<0 || i>=m || j>=n) return;
    if(pic[i][j] != '@' || flag[i][j]>0 ) return;
    flag[i][j]=id;
    for(int ii=-1;ii<=1;ii++)
        for(int jj=-1;jj<=1;jj++)
            if(ii!=0 || jj !=0)
            dfs(i+ii,j+jj,id);
}

int main()
{
    while(cin >> m >> n,m)
    {
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                cin >> pic[i][j];

        memset(flag,0,sizeof(flag));


        int id=0;

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            if(flag[i][j]==0 && pic[i][j]=='@')
            dfs(i,j,++id);

        cout << id <<endl;
    }
    return 0;
}
