#include <iostream>
using namespace std;

long long ff(long long n){
	long long f=0,g=1;

	while(n--){
		g=f+g;
		f=g-f;
	}
	return g;
}


int main()
{

	long long n;
	cin >> n;

	cout << ff(n) << endl;

	return 0;
}