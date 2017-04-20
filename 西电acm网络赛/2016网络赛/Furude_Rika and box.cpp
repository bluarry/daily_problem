#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define N 100000005
using namespace std;
typedef long long ll;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int t;cin >> t;
	while(t--){
		ll Q;
		cin >> Q;
		int flag=0;

		if(Q%2==1)
		{
			flag=1;
		}
		else if( (Q&1)==0 &&((Q/2)&1)==1)
		{
			flag=2;
		}
		else
		{
			ll i=0;
			while(Q!=2)
			{
				if((Q&1) ==1) break;
				Q/=2;
				i++;
			}
			if(Q==2)
			{	if((i&1)==1) flag=1;
				else flag=2;
			}
			else
			{
				if(i&1) flag=2;
				else flag=1;
			}


		}
	if(1==flag)
	{
		cout << "First Box"<<endl;	
	}
	else if(2==flag)
	{
		cout << "Second Box"<<endl;
	}
	}
	return 0;
}
