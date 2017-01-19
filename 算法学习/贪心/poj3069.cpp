#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1000+5;
int N,R;
int armmy[maxn];
int main()
{
    //freopen("./in","r",stdin);
    while(cin >> R >> N)
    {
        if(N==-1) break;

        for(int i=0;i<N;i++)
        {
            cin >> armmy[i];
        }

        sort(armmy,armmy+N);
        int i=0,ans=0;
        while(i<N)
        {
            int s=armmy[i++];
            while(i<N && armmy[i]<=s+R)i++;

            int p=armmy[i-1];
            while(i<N && armmy[i]<=p+R)i++;

            ans++;
        }

        cout << ans << endl;
    }


    return 0;
}
