#include <cstdio>
#include <stack>
#include <iostream>
using namespace std;
const int maxn=1000+10;

int n,target[maxn];

int main()
{
	//freopen("D:\\1.in","r",stdin);
	while(cin >> n){
		stack<int > s;
		int A=1,B=1; 
		for(int i=1;i<=n;i++)
			cin >> target[i];
		int ok=1;
		while(B<=n){
			if(A==target[B]) {A++;B++;}
			else if(!s.empty() && s.top() == target[B]) {s.pop();B++;}
			else if(A<=n) s.push(A++);
			else {ok=0;break;}
	}
	cout <<  (ok?"yes":"no") << endl;
	}
return 0;
}
