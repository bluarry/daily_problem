#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
	ll n,c,data[100000+5];

	cin >> n >> c;


	for(int i=0;i<n;i++)
	{
		cin >> data[i];
	}
	ll count=1;
	for(int i=1;i<n;i++){
		if(data[i]-data[i-1] <= c)
		{	
			count++;
		}
		else
		{
			count=1;
		}

	}
	cout << count << endl;






	return 0;
}
