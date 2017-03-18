#include <iostream>
#include <cstring>
using namespace std;

int n,m;
int linkr[15][15],linkc[15][15];

int has(int s,int n)
{
    int sum=0;
    for(int i=1;i<=n-s+1;i++)
        for(int j=1;j<=n-s+1;j++)
            {
                int k,ok=1;
                for(k=i;k<i+s;k++) if(!linkc[j][k]||!linkc[j+s][k]) {ok=0;break;}
                //枚举行
                for(k=j;k<j+s;k++) if(!linkr[i][k] || !linkr[i+s][k]){ok=0;break;}
                //枚举列
                if(ok) sum++;
            }
        return sum;
}
int main()
{
    int times=1,x,y;
    char cmd;
    while(cin >> n)
    {
        memset(linkr,0,sizeof(linkr));
        memset(linkc,0,sizeof(linkc));
        if(times-1) cout <<"\n**********************************\n\n";
        cout << "Problem #"<< times++ <<"\n\n";
        cin >> m;
        while (m--) {
            cin >> cmd >> x >> y;
            if(cmd == 'H')linkr[x][y]=1;
            else if(cmd == 'V') linkc[x][y]=1;
        }

        int s=1; //当前的枚举边长
        int ok=0;
        while(s<n)
        {

            if(has(s,n-1)) //枚举边长为s时可以构成的正方形个数,病返回
            {
                ok=1;
                cout << has(s,n-1)<<" square (s) of size "<< s;
                cout << "\n";
            }
            s++;
        }
        if(!ok) cout << "No completed squares can be found." <<endl;



    }

    return 0;
}
