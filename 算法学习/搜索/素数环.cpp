#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
int isp[100];
int is_prime(int n)
{
    int m=n;
    for(int i=2;i<=(int)sqrt(m);i++)
    {
        if(! (m % i))
        {
            return 0;
        }
    }
    return 1;
}
int A[35];
int vis[35];
void dfs(int cur)
{
    if(cur==n && isp[A[0]+A[n-1]])
    {
        for(int i=0;i<n;i++) i==n-1 ? cout << A[i]: cout << A[i]<<" ";
        cout <<endl;
    }
    else for(int i=2;i<=n;i++)
    {
        if(!vis[i] && isp[i+A[cur-1]])
        {
            A[cur]=i;
            vis[i]=1;
            dfs(cur+1);
            vis[i]=0;
        }
    }
}


int main() {
    int dd=1;
    while(cin >> n){
    if(dd!=1)cout << endl;
    cout << "Case "<<dd++<<":"<<endl;
    for(int i=2;i<=2*n;i++)isp[i]=is_prime(i);
    A[0]=1;
    vis[1]=1;
    dfs(1);
    }
    return 0;
}
