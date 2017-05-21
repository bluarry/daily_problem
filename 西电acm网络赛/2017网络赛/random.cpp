#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	freopen(".\\in.txt","w",stdout);
	srand(time(0));
	for(int i=0;i<1000;i++) cout << rand()<< " ";
	return 0;
}
