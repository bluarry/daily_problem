#include <iostream>

using namespace std;
int main()
{
	int hs=456489%47;
	int rehs=((456489%9009)*3)%10+1;
	int x=0;	
	for(int i=0;i<100;i++)
	{
		x=(hs+rehs)%50;
		hs=x;
		cout << hs << " ";
	}
	cout << endl;

}
