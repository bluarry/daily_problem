#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
const int maxn=1000005;
int A[1000005],r[1000005],c[1000005];
char ans[3][20]={"Phone","Empty","Tree"};
string ss;

int main()
{
	freopen("in.txt","r",stdin);
	int n,m;
	int cases=1;
	while(cin >> n >> m)
	{
		int cnt=0;
       for(int i=1;i<=n;i++) r[i]=i;
       for(int j=1;j<=m;j++) c[j]=j;
       for(int i=1;i<=n;i++)
       {
          cin >> ss;
           for(int j=0;j<ss.length();j++)
           {
                if(ss[j]=='T')
                    A[++cnt]=1;
                else if(ss[j]=='i')
                    A[++cnt]=-1;
                else
                    A[++cnt]=0;
           }
       }
       int Q,a,b,op;
       cin >> Q;
    	cout << "Case #"<<cases++<< ":\n";
       while(Q--)
       {
           cin >> op >> a >>b;
           if(op == 1)
           {
               int x=A[(r[a] - 1) * m + c[b]];
               puts(ans[x+1]);
           }
           else if(op == 2)
           {
               int t = r[a];
               r[a] = r[b];
               r[b] = t;
           }
           else
           {
               int t =c[a];
               c[a] = c[b];
               c[b] = t;
           }
       }

      }




	return 0;
}
