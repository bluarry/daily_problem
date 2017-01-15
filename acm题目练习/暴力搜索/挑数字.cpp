#include <iostream>
using namespace std;
const int max_n=100;
int a[max_n];
int n,k;
bool dfs(int i,int sum)
{
    if(i==n) return sum == k;

    if(dfs(i+1,sum)) return true;

    if(dfs(i+1,sum+a[i])) return true;

    return false;
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
            cin >> a[i];
    cin >> k;

    if(dfs(0,0)) cout << "yes!" << endl;
    else
        cout << "no!"<<endl;

    return 0;
}
