#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(int argc, char const *argv[])
{
	freopen("in.txt","w",stdout);
	srand(time(0));
	int T=3000;
	while(T--){
		int n=rand()%int(1e5)+1,k=rand()%int(1e9+1);
		cout << n <<' '<< k<<endl;
		for(int i=0;i<n;i++)
			i!=n-1?cout << rand()%int(1e9+1)<< " ":cout << rand()%int(1e9+1)<<endl;
	}
	return 0;
}
