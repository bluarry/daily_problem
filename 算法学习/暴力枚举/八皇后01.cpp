/*
只求八皇后的解的个数
*/
#include <iostream>
using namespace std;
const int maxn=1000;
int n,tot=0;
int C[maxn];
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
        int ok=1;
        C[cur]=i;
        for(int j=0;j<cur;j++)
        if(C[j]== C[cur] || cur-C[cur] == j-C[j] || cur+C[cur]==j+C[j] )
            {ok=0;break;}
        if(ok)
            search(cur+1);
    }
}


int main()
{
    cin >> n;
    search(0);
    cout <<"共有 "<<tot <<"种摆法"<< endl;

    return 0;
}
