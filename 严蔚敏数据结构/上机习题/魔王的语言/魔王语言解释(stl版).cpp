#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
int main()
{
    cout << "请输入魔王的语言 : ";
    //char tar[]="B(ehnxgz)B";
    string tar;
    cin >> tar;
    char ee;
    stack<char> s;
    queue<char> q;

    cout << "翻译为 : ";
    int len=tar.length();
    //把所有的字母倒着压栈
    for(int i=len-1;i>=0;--i)
    {
        s.push(tar[i]);
    }
    while(!s.empty())
    {
        char tem=s.top();s.pop();
        if(tem==')') 
				continue;
        if(tem=='B')    // 大写字母B处理
        {
            cout << "tsaedsae";
        }
        else if(tem=='A')//大写字母A处理
        {
                cout << "sae";
        }
        else if(tem=='(')   //遇到括号的处理
        {
            ee=s.top();//s.pop();
            char x=ee;  //得到si‘ta
            while(1)    //将括号里的字母入队
            {
                x=s.top();s.pop();
                if(x==')') break;
                q.push(x);
            }
            //出栈结束的标志入栈
            s.push(')');

            while(!q.empty()) //将队列里的元素顺序入栈
            {
                char y=q.front();
                q.pop();
                s.push(y);
            }
            char as='0';    //每个元素加si'ta，出栈
            while(1)
            {
                as=s.top();s.pop();
                if(as==')') break;
                if(as=='B'){
                    cout << ee << "tsaedsae";
                }
                else if (as=='A')
                {
                       cout <<ee <<"sae";
                }
                else
                	if (ee!=as)
                    cout << ee << as ;
            		else
            		cout << ee;
			}
        }
        else
        {
            cout << tem;
        }
    }
    cout << endl;
    return 0;
}

