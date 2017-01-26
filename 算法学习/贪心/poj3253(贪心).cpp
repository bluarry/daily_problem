#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=2000+5;
typedef long long ll;
int N;
int L[maxn];
int main()
{
    //freopen("./in","r",stdin);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> L[i];
    }

    ll ans=0;
    while(N>1)
    {
        int min1=0,min2=1;
        if(L[min1]>L[min2]) swap(min1,min2);

        for(int i=2;i<N;i++)
        {
            if(L[i]<L[min1])
            {
                L[min2]=L[min1];
                L[min1]=L[i];
            }
            else if(L[i]<L[min2])
            {
                L[min2]=L[i];
            }
        }

        int ts=L[min1]+L[min2];
        ans+=ts;
        if(min1==N-1) swap(min1,min2);
        L[min1]=ts;
        L[min2]=L[N-1];
        N--;
    }
    cout << ans << endl;


    return 0;
}
