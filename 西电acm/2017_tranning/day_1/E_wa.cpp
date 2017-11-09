#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
int main()
{
    freopen("in.txt","r",stdin);
    ll a,b;
    while(cin >> a >> b){
        ll k=abs(a-b);
        a=a<b?a:b;
        ll a_x=floor(k*((1.0+sqrt(5.0))/2));
        cout << (a_x!=a) << endl;
    }
    return 0;
}
