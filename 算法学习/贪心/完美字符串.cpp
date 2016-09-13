#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	for(int i=0;i<s.length();i++)
		if(isalpha(s[i])) s[i]=tolower(s[i]);
	int count[26]={0};
	for(int i=0;i<s.length();i++)
		++count[s[i]-'a'];
	sort(count,count+26);
	long long sum=0;
	for(int i=25;i>=0 && count[i];i--)
		sum += count[i]*(i+1);
	cout << sum << endl;
	return 0;
}
