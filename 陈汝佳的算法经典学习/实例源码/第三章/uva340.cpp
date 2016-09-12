//Master-Mind Hints
//http://acm.hust.edu.cn/vjudge/problem/18657
//#define LOCAL
#include <stdio.h>
#define maxn 1010
int main()
{
//	#ifdef LOCAL
//	freopen("D:\\in.txt","r",stdin);
//	#endif
	int n,a[maxn],b[maxn];
	int kcase=1;
	while(EOF!=scanf("%d",&n) && n){
		printf("Game %d:\n",kcase++);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		while(1)
		{
			int A=0,B=0;
			for(int i=0;i<n;i++)
			{
				scanf("%d",&b[i]);
				if(a[i]==b[i]) A++;
			}
			if(b[0]==0) break;
			for(int d=1;d<=9;d++)
			{
				int c1=0,c2=0;
				for(int i=0;i<n;i++)
				{
					if(a[i]==d) c1++;
					if(b[i]==d) c2++;
				}
				B+= (c1<c2?c1:c2);
			}
			printf("    (%d,%d)\n",A,B-A);
		}

	}
	return 0;
}
