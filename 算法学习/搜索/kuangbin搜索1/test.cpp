#include <iostream>
using namespace std;


int main()
{

int n,k;

	while(cin >> n >> k)
	{
		int fenzi=1;
		for(int i=0;i<k;i++)
			fenzi*=(n-i);
			cout << fenzi << endl;
		int fenmu=1;
		for(int i=1;i<=k;i++)
			fenmu*=i;
			cout << fenmu << endl;
		int result= fenzi/fenmu;
		cout << result << endl;
	}



	return 0;
}
