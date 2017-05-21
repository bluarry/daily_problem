#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int cnt=0;
	int len=s.length();
	for(int i=0;i<(int)(len/2.0);i++)
	{
		if(s[i]!=s[len-1-i]) cnt++;
	}
	if(cnt==1) cout << "YES" ;
	else if(cnt==0){
		if(len%2){
			cout << "YES";
		}
		else cout << "NO";
	}
	else
		cout << "NO";


	return 0;
}
