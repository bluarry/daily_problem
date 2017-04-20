#include <iostream>
using namespace std;
int main(){
	int m,n;
	cin >> m >> n;
	int sum=0;
	int x;
	for(int i=1;i<=n;i++)
	{
		cin >> x;
		sum+=x;
		if(x >= m ) break;
	}
	cout << x << endl;

	return 0;
}
