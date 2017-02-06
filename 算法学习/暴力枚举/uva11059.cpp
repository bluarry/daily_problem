#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
int s[20];
int main()
{
    int ca=1;
    while(cin >> n)
    {
        for(int i=0;i<n;i++)
        cin >> s[i];
        int begin;
        int second;
        ll res=0;
        for(begin=0;begin<n;begin++)
            for(second=begin;second<n;second++)
            {
                ll cheng=1;
                for(int i=begin;i<=second;i++)
                {
                    cheng *= s[i];
                }
                res=max(res,cheng);
                //cout << res <<endl;
            }
    if(res < 0) res=0;

    cout << "Case #"<<ca++<<": The maximum product is "<< res <<"."<<endl<<endl;
    }
    return 0;
}
