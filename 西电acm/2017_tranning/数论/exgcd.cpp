#include <iostream>
using namespace std;
void ex_gcd(int a,int b,int& d,int& x,int& y){
	if(b==0){
		d=a;
		x=1;y=0;
	}
	else {
		ex_gcd(b,a%b,d,y,x);
		y-=x*(a/b);
	}
}

int main()
{
	int a,b,d,x,y;
	ex_gcd(963,657,d,x,y);
	cout << d <<" "<< x <<" "<< y <<endl;



	return 0;
}
