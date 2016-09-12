#include <cstdio>
#include <stack>
#include <iostream>
#define LOCAL
using namespace std;
const int maxn=1000+10;

int n,target[maxn];

int main()
{
	#ifdef LOCAL
	freopen("D:\\1.in","r",stdin);
	#endif
	while(cin >> n && n ){
		while(cin>> target[1] && target[1])
		{
		for(int i=2;i<=n;i++)
			cin >> target[i];
		stack<int > s;
		int A=1,B=1; 
		int ok=1;
		while(B<=n)
		{
			if(A==target[B]) 
			{
				A++;
				B++;
			}
			else if(!s.empty() && s.top() == target[B])
			 {
			 	s.pop();
				 B++;
			}
			else if(A<=n) s.push(A++);
			else {ok=0;break;}
		}
		
		cout <<  (ok?"Yes":"No") << endl;
		}
		cout << endl;
	}
return 0;
}
