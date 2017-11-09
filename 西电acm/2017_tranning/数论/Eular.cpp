#include <iostream>
using namespace std;
int Eular(int a)
{
	int xa=a;
	for(int i=2;i*i<=a;i++)
	{
		if(0==a%i){
			xa=xa/i*(i-1);
			while(!(a%i))a/=i;
		}
	}
	if(a!=1){
		xa=xa/a*(a-1);
	}
	return xa;
}
int main()
{
	int n;
	while(cin >> n)
	{
		cout << Eular(n)<<endl;
	}


	return 0;
}
