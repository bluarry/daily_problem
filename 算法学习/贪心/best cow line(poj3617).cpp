#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=2000+5;
int N;
char st[maxn];
int main()
{
   // freopen("./in","r",stdin);
  cin >> N;
    for(int i=0;i<N;i++)
        cin >> st[i];

    int a=0,b=N-1,CO=0;
    while(a<=b)
    {
        bool left=false;

        for(int i=0;a+i<=b;i++)
        {
            if(st[a+i] < st[b-i])
            {
                left=true;
                break;
            }
            else if(st[a+i] > st[b-i])
            {
                left=false;
                break;
            }

        }
        CO++;
        if(left) cout << st[a++];
        else cout << st[b--];
         if(CO%80==0) cout << endl;
    }





    return 0;
}

