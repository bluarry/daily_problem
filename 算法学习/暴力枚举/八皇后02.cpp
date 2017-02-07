/*
对八皇后进行优化
*/
/*
只求八皇后的解的个数
*/
#include <iostream>
using namespace std;
const int maxn=1000;
int n,tot=0;
int C[maxn];
int vis[3][maxn];
void print()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(C[i]==j)
                cout << "* ";
            else
                cout << "0 ";
        if(j==n-1)  cout << endl;
        }
        cout << endl;
        tot++;
}
void search(int cur)
{
    if(cur==n) print();
    else for(int i=0;i<n;i++)   //枚举列
    {
        if(!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+n])
        {
            C[cur]=i;
            vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=1;
            search(cur+1);
            vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=0;
        }
    }
}
int main()
{
    cin >> n;
    search(0);
    cout <<"共有 "<<tot <<"种摆法"<< endl;
    return 0;
}
