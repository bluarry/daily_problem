#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;
int main()
{
    freopen("in.txt","w",stdout);
    srand(time(0));
    int T=100;
    cout << T <<endl;
    while(T--){
        int n=rand()%10000;
        cout << n << endl;
        for(int i=0;i<n;i++)
            {
                int l,r;
                l=rand()%10000000;
                r=l+rand()%(10000000-l);
                cout << l << " "<< r << endl;
            }
    }

    return 0;
}
