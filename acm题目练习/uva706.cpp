#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long ll;
const int maxn=8;

void draw_number(ll s,ll n)
{
    int dist[maxn];
    memset(dist,-1,sizeof(dist));
    if(n==0){
        dist[maxn-1]=0;
    }
    else
    {
        ll x=n;
        int i=maxn-1;
        while (x) {
            dist[i--]=x%10;
            x/=10;
        }
    }

    string outline[5][10]={//5行３列的:0 1 2 3 4 5 6 7 8 9 得到关键字,之后根据ｓ进行扩大即可
        " - ","   "," - "," - ","   "," - "," - "," - "," - "," - ",
        "| |","  |","  |","  |","| |","|  ","|  ","  |","| |","| |",
        "   ","   "," - "," - "," - "," - "," - ","   "," - "," - ",
        "| |","  |","|  ","  |","  |","  |","| |","  |","| |","  |",
        " - ","   "," - "," - ","   "," - "," - ","   "," - "," - ",
    };


    for(int raw=1;raw<=(s*2+3);raw++)
    {
        for(int i=0;i<maxn;i++)
            if(dist[i]!=-1)
            {
                string keywords;
                //得到每一行的关键字
                if(raw==1)
                    keywords=outline[0][dist[i]];
                else if(raw>1 && raw < s+2)
                    keywords=outline[1][dist[i]];
                else if(raw == s+2)
                    keywords=outline[2][dist[i]];
                else if(raw > s+2 && raw < 2*s+3)
                    keywords=outline[3][dist[i]];
                else if(raw == 2*s+3)
                    keywords=outline[4][dist[i]];

                cout << keywords[0];
                for(int j=0;j<s;j++)
                cout << keywords[1];
                cout << keywords[2];

                if(i<maxn-1)
                cout << " ";
            }
    cout << endl;
    }
}
int main()
{
    ll s,n;
    while(cin >> s >> n,s||n)
    {
        draw_number(s,n);
        cout << endl;
    }
    return 0;
}
/**
6 35138132
5 6584131
10 543
1 99999999
9 135
2 351381
4 6846354
10 0
5 1094
4 11111
3 18818818
1 0
2 0
3 0
8 31415
2 007
0 0
*/
