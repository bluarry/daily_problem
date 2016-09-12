#include <iostream>
using namespace std;

typedef long long ll;
int main()
{

	int k;
	while(cin >> k)
	{
		int c=0;
		for(ll y=k+1;y<= 2*k;y++)
		{
			if((k*y) % (y-k) ==0)
			{
				ll x=(k*y)/(y-k);
				if(x>=y)
					c++;
			}
		}
		cout <<c<< endl;

		for(ll y=k+1;y<=2*k;y++)
		{
			if((k*y) % (y-k) ==0)
			{
				ll x=(k*y)/(y-k);
				if(x>=y)
				{
					cout << "1/" << k << " = " << "1/"<<x<<" + "<<"1/"<<y << endl;
				}
			}

		}
	}
	return 0;
}
