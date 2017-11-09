#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=60;
int num[5],k,d,last;
bool x[maxn];
int getlast(int k,int d)
{
    int hh=0;       //求出之后的所有
    for(int i=1;i<k;i++)
        hh+=num[i];
    int last=hh+(num[k]-d);
    return last;
}
int last_1(int a,int d)
{
    if(a-d<=0) return 55-(a-d);
    else return a-d;
}
void init(int k,int d)
{
    int last=getlast(k,d);
    x[last]=x[last_1(last,1)]=true;
}

bool solve(int a,int b)
{
    int last=getlast(a,b);

    if(x[last] && x[last_1(last,1)] || x[last_1(last,8)]&&x[last_1(last,9)] || x[last_1(last,16)]&&x[last_1(last,17)]  )
        return true;

    return false;
}
int main()
{
    while(cin >> num[1] >> num[2]>> num[3] >> num[4]){
        memset(x,0,sizeof(x));
        cin >> k >>d;

        init(k,d);

        int ans=0;
        for(int i=1;i<6;i++)
            for(int j=i;j<8;j++)
                if(int a=solve(i,j))
                {
                    cout << i << " "<<j <<endl;
                    ans+=a;
                }
        cout << ans <<endl;
    }
    return 0;
}
