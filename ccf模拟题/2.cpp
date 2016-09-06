#include <iostream>
#include <cstring>
using namespace std;



int main()
{
	int a,b,c;
	char d,x;
	cin >> a >>d>>b >> d >> c >>d;
	cin >> x;
	int sum=0;
	//a 1  (1)
	//b 3	(2-4)
	//c 5	(5-9)
	sum=a*1+( 4*(b%10)+3*((b/10)%10)+2*((b/100)%10)) + ( 9*(c%10)+8*((c/10)%10) + 7*((c/100)%10)+6*((c/1000)%10)+ 5*((c/10000)%10)  );
	sum%=11;
	if(sum <=9)
	{
		if(sum==(x-'0'))
			cout << "Right"<<endl;
		else
			cout << a << '-'<<b<<'-'<<c<< '-'<<sum;
	}
	else
		if(x=='X')
			cout << "Right"<<endl;
		else 
			cout << a << '-'<<b<<'-'<<c<< '-'<<'X';
	return 0;
}
