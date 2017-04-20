#include <map>
#include <set>
#include <queue>
#include <vector>
#include <iostream>
//#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <ctime>
using namespace std;
const int maxn=5000+5;
typedef long long ll;
string s[maxn];
int n;
map<string,string > M1;
typedef map<string, vector<string > > VECTOR2STRING;
VECTOR2STRING M2;
string getid(const string &ss)
{
	string x=ss;
	sort(x.begin(),x.end());
	return x;
}
//超时原因是map为clear
int main(){
	//freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

//int start_1=clock();


	while(cin >> n)
	{
	M1.clear();
	for(int i=0;i<n;i++)
	{
		cin >> s[i];
		M1.insert(map<string,string >::value_type(s[i],getid(s[i])));
	}

	M2.clear();
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
		if(M2.find(M1[s[i]])==M2.end())
		{
			continue;
		}
		else
		{
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
			M2.erase(M2.find(M1[s[i]]));
		}
	}

	}

//int end_1=clock();
//	cout << "\n\n run time is  : " << end_1-start_1 << " ms"<< endl;

	return 0;
}
