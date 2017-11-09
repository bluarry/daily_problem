#include <iostream>
using namespace std;
int main()
{
	int n,k;
	cin >> n >>k;
	string s;
	cin >> s;
	int c[26]={0};
	for(int i=0;i<n;i++)
		c[s[i]-'a']++;
	int flag=1;
	for(int i=0;i<26;i++)
		if(c[i] > k) flag=0;
	if(flag) cout << "YES"<<endl;
	else cout << "NO" <<endl;

	return 0;
}