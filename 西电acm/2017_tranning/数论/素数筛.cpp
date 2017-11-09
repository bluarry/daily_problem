#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=1e6;

bool isprime[maxn];
std::vector<int> v;
void oula_prime(int n)
{
	memset(isprime,true,sizeof isprime);
	isprime[1]=false;
	for(int i=2;i<=n;i++)
	{
		if(isprime[i]) v.push_back(i);
		for(int j=0;j<v.size() && i*v[j]<=n;j++){
			isprime[i*v[j]]=false;
			if(i%v[j]==0) break;
		}
	}

}

int main()
{
	oula_prime(10000);
	int x;
	for(int i=0;i<v.size();i++)cout << v[i]<<endl;
	while(cin >> x)
	{
		cout << isprime[x] << endl;
	}


	return 0;
}
