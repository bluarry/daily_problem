#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <stack>
using namespace std;
int main()
{
	//freopen("in.txt","r",stdin);
	map<string,string> M;
	M.insert(map<string,string>::value_type("v8","SingleDog&YangRouHuoGuo"));
	M.insert(map<string,string>::value_type("qsqx","Couple&Program"));
	M.insert(map<string,string>::value_type("lbz007","SingleDog&GoodGoodStud"));
	string s;
	while(cin >> s){
		cout << M[s] <<endl;
	}	
	
	
	return 0;
}
