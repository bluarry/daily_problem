#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <stack>
#define maxn 1000
#define INFITY 32767

using namespace std;



int vexnum,adgnum;
int adj[maxn][maxn];
string vex[maxn];



int locate( string a )
{
    for(int i=0;i<vexnum;i++)
        if(a==vex[i]) return i;
    return -1;
}
void print_path(int P[][maxn] , int x , int v0)
{
    stack<int> s;
    int y=x;//x==y=2
    for(;x!=-1 && x!=v0;x=P[v0][x])
    {
           s.push(x);
    }
    s.push(v0);
    if(x!=v0)
    {
          cout<<vex[v0] << "到 " << vex[y] << " 无路径"<< endl;
          return ;
   }


    cout <<vex[v0] << "到 " << vex[y] << " 的路径为 : ";

      while(!s.empty())
      {
          cout << vex[s.top()] << " ";
          s.pop();
      }
      cout << endl;
}

void short_floyd()
{
    int D[maxn][maxn],P[maxn][maxn];
    for(int i=0;i<vexnum;i++)
        for(int j=0;j<vexnum;j++)
        {
            D[i][j]=adj[i][j];
            if(D[i][j]!=INFITY) P[i][j]=i;
            else P[i][j]=-1;
        }
    for(int k=0;k<vexnum;k++)
        for(int i=0;i<vexnum;i++)
            for(int j=0;j<vexnum;j++)
            {
                if(D[i][k]+D[k][j] < D[i][j])
                {
                    D[i][j]=D[i][k]+D[k][j];
                    P[i][j]=P[k][j];
                }
            }
        for(int i=0;i<vexnum;i++)
            for(int j=0;j<vexnum;j++) //下标从i到j的路径
            {
                print_path(P,j,i);
                cout << " 最短的路径长度为 : " << D[i][j] << endl;
            }
}

int main()
{
    //freopen("./in1","r",stdin);
 /*in1
4 8
0 1 2 3
0 1 1
0 3 4
1 3 2
1 2 9
2 1 5
2 3 8
2 0 3
3 2 6
*/
    cin >> vexnum >> adgnum;
    for(int i=0;i<vexnum;i++)
    {
        cin >> vex[i];
    }
    string a,b;
    //有向图的构建
    for(int i=0;i<vexnum;i++)
        for(int j=0;j<vexnum;j++)
            i==j?adj[i][j]= 0 :adj[i][j]= INFITY;
    for(int i=0;i<adgnum;i++)
    {
        cin >> a >> b;
        int x=locate(a);
        int y=locate(b);
        if(x<0 || y< 0) exit(-1);
        cin >> adj[x][y];
    }

    short_floyd();
    return 0;
}

