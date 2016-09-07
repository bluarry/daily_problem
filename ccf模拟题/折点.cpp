#include <iostream>
using namespace std;

int main()
{

	int n;
	cin >> n;
	int x[10005];
	int count=0;
	for(int i=0;i<n;i++)
	{	
		cin >> x[i];
	}
	for(int i=1;i<=n-2;i++)
		if(x[i-1] < x[i] && x[i] > x[i+1] || x[i-1] > x[i] && x[i] < x[i+1]  )
				count++;

			cout << count<< endl;





	return 0;
}
