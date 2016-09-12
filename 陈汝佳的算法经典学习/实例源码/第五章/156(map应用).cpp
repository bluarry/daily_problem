#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map< string , int >cnt;
vector<string> words; 

string repr(const string& s)
{	
	string ans=s;
	for(int i=0;i<ans.length();i++)
	ans[i]=tolower(ans[i]);
	sort(ans.begin(),ans.end());
	return ans;
}


int main()
{
	//freopen("D:\\1.in","r",stdin);
	int n=0;
	string s;
	while(cin >> s)
	{
		if(s[0]=='#') break;
		words.push_back(s);
		string r=repr(s);
		if(!cnt.count(r)) cnt[r]=0;
		cnt[r]++;
	}  //统计某个字符串出现没有，并把原来的单词放入vector
	vector<string> ans;
	for(int i=0;i<words.size();i++)
	{
		if(cnt[repr(words[i])]==1) ans.push_back(words[i]);
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
		cout << ans[i] << endl;
	return 0;
}
