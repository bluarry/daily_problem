#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
typedef long long ll;
priority_queue<ll,vector<ll>,greater<ll> > small;
ll n,k;
void inset(ll x)
{
    if((int)small.size()< k )
    {
        small.push(x);
        return;
    }
    if(x>small.top())
    {
        ll a=small.top();
        small.pop();
        small.push(x);
    }
}
ll query()
{
    return small.top();
}
int main() {
    // freopen("in.txt","r",stdin);
    char cc;
    while(EOF!=scanf("%lld %lld ",&n,&k)){
        while(small.size()>0) small.pop();
        while(n--){
            scanf("%c ",&cc);
            if(cc =='I')
            {
                ll a;
                scanf("%lld ",&a);
                inset(a);
            }
            else if(cc =='Q'){
                printf("%lld\n",query() );
            }
        }
    }
    return 0;
}
