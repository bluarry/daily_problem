#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
int main()
{
	char tar[]="B(ehnxgz)B";
	char ee;
	stack<char> s;
	queue<char> q;

	int len=strlen(tar);
	for(int i=len-1;i>=0;--i)
	{
		s.push(tar[i]);
	}
	while(!s.empty())
	{	
		char tem=s.top();s.pop();
		if(tem=='B')
		{
			cout << "tsaedsae";
		}
		else if(tem=='(')
		{
			/******************///***********这一段是把小写字母压入队列，并把他们取出来在压栈，在弹栈
			ee=s.top();s.pop();
			char x=ee;
			while(1)
			{
				x=s.top();s.pop();
				if(x==')') break;
				q.push(x);
			}
			while(!q.empty())
			{
				char y=q.front();
				q.pop();
				s.push(y);
			}

			while(1)
			{
				char as=s.top();s.pop();
				if(as=='B'){
					cout << "tsaedsae";
					break;
				}
				cout << ee << as ;
			}
		}
	}
	return 0;
}
