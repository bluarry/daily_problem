#include <iostream>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int start=0;
	long long sum=0;
	for(int i=0;i<s.length();i++){
		int cha=(s[i]-'a'-start+26)%26;
		if(cha>13) cha=26-cha;
		sum+=cha;
		start=s[i]-'a';
	}
	cout << sum << endl;




	return 0;
}