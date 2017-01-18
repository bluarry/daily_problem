#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=2000+5;
int N;
char st[maxn];
int main()
{
	freopen("./in","r",stdin);
    cin >> N;
    getchar();
    for(int i=0;i<N;i++)
    	cin >> st[i];

    for(int i=0;i<N;i++)
    	cout << st[i];
    cout << endl;

    int a=0,b=N-1;
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
    	if(left) cout << st[a++];
    	else cout << st[b--];
    }
    cout << endl;








    return 0;
}
