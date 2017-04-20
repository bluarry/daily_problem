#include <map>
#include <set>
#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=5000;
typedef long long ll;
string s[maxn];
int n;
int pp[]={1,10,100,1000,10000,100000,1000000,10000000};
map<string,int > M1;
typedef map<int, vector<string > > VECTOR2STRING;
int getid(string ss)
{
	int ch[8];
	for(int i=0;i<ss.length();i++)
		ch[i]=ss[i]-'a';
	sort(ch,ch+ss.length());
	int id=0;
	for(int i=0;i<ss.length();i++)
	{
		id+=ch[i]*pp[i];
	}
	return id;
}

void f1()	//将string map到id
{
	for(int i=0;i<n;i++)
	{
		int id=getid(s[i]);
		M1.insert(map<string,int >::value_type(s[i],id));
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","a",stdout);
	while(cin >> n)
	{
	
	M1.clear();
	for(int i=0;i<n;i++)
	{
		cin >> s[i];
		f1();//将string map到id
	}
	VECTOR2STRING M2;
	set<int> xx,yy;
	yy.clear();


	for(int i=0;i<n;i++)
	{
		if(M2.find(M1[s[i]]) == M2.end())
		{
			M2.insert(VECTOR2STRING::value_type(M1[s[i]], *(new vector<string>)));
			 VECTOR2STRING::iterator iter=M2.find(M1[s[i]]);
			 iter->second.push_back(s[i]);
		}else 
		{
			VECTOR2STRING::iterator iter=M2.find(M1[s[i]]);
			 iter->second.push_back(s[i]);
		}
	}


	for(int i=0;i<n;i++)
	{
		if(yy.find(M1[s[i]])!=yy.end())
		{
			continue;
		}
		else
		{
			yy.insert(M1[s[i]]);
			VECTOR2STRING::iterator iter=M2.find(M1[s[i]]);
			vector<string>::iterator it = iter->second.begin();
			vector<string>::iterator it1= iter->second.end();
			it1--;
			while(it!=iter->second.end())
			{
				if(it!=it1)
				cout << (*it++) << " ";
				else 
					cout << (*it++) << endl;
			}
		}
	}
}
	return 0;
}
