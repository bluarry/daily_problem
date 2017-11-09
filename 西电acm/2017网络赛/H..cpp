#include <map>
#include <set>
#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
typedef long long ll;

int a,b,s,t,c,d;
bool can()
{
	if( ( (a%(c+1))^ (b%(d+1))) )
	{
		return true;
	}

return false;
}
int main()
{
	while(cin >> a >> b >> c >> d)
	{

		if(can())
		{
			cout << "NUO!"<<endl;
		}
		else 
		{
			cout << "NO!" << endl;
		}


	}
	return 0;
}
