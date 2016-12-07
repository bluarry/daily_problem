#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

const int maxn=250+5;
int m,n;
int dir_x[] ={0,0,1,-1};
int dir_y[] ={1,-1,0,0};
char map[maxn][maxn];

void fill(int x,int y,char c,char s)
{
    if(map[x][y]!=s) return;
    if(x<1 || y<1) return ;
    if(x>n || y >m) return ;
    map[x][y]=c;
    for(int i=0;i<4;i++)
        fill(x+dir_x[i],y+dir_y[i],c,s);
}





int main()
{
    char qq='0';
    while(qq!='X')
    {
        cin >> qq;
        m=250,n=250;
        switch (qq)
        {
            case 'I':{
                cin >> m >> n;
                for(int i=1;i<=n;i++)
                    for(int j=1;j<=m;j++)
                    {
                        map[i][j]='O';
                    }
                break;
            }
            case 'C':{
                for(int i=1;i<=n;i++)
                    for(int j=1;j<=m;j++)
                    {
                        map[i][j]='O';
                    }
                break;
            }
            case  'L':{
                int xl,yl;
                char cl;
                cin >> xl >> yl >> cl;
                map[yl][xl]=cl;
               break;
           }
            case 'V':{
                int xv,yv1,yv2;
                char cv;
                cin >> xv >> yv1 >> yv2>>cv;
                for(int i=min(yv1,yv2);i<=max(yv1,yv2);i++)
                {
                    map[i][xv]=cv;
                }
               break;
            }
            case 'H':{
                int xh1,xh2,yh;
                char ch;
                cin >> xh1 >> xh2 >> yh >> ch;
                for(int i=min(xh1,xh2);i<=max(xh1,xh2);i++)
                    map[yh][i]=ch;
                break;
            }
            case 'K':
                {
                int xk1,yk1,xk2,yk2;
                char ck;
                cin >> xk1 >> yk1 >> xk2 >> yk2 >> ck;
                for(int i=xk1;i<=xk2;i++)
                    for(int j=yk1;j<=yk2;j++)
                        map[i][j]=ck;
                break;
            }
            case 'F':
            {
                int xf,yf;
                char cf;
                cin >> xf>> yf >> cf;

                for(int i=0;i<4;i++)
                fill(yf+dir_x[i],xf+dir_y[i],cf,map[yf][xf]);
                    break;
            }
            case 'S':
                {
                string ss;
                cin >> ss;
                cout << ss<<endl;
                for(int i=1;i<=n;i++)
                    for(int j=1;j<=m;j++)
                    j==m?cout << map[i][j]<< "laji"<< endl : cout <<"laji"<<  map[i][j];
                    break;
                }
        }
    }
    return 0;
}
