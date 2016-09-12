#include <iostream>
#include <cstring>
using namespace std;

int hehe[1005];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	while(cin >> n){
	
	for(int i=1;i<=n;i++)
		cin >> hehe[i];

	int vi[10005];
	memset(vi,0,sizeof(vi));
	for(int i=1;i<=n;i++)
		vi[hehe[i]]++;
	int flag=0,k=0;
	for(int i=1;i<=10000;i++)
		if(vi[i]>flag)
		{
			flag=vi[i];
			k=i;
		}
	cout << k << endl;
	}


	return 0;
}
