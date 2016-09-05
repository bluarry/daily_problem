#include <stdio.h>
typedef long long ll; 
//#define LOCAL
int main ()
{
	#ifdef LOCAL
	freopen("D:\\1.in","r",stdin);
	#endif
	 ll k=0,data[100],a=0;
	while(~scanf("%lld",&k)){
		for(int i=0;i<k;i++)
		{
			scanf("%lld",&data[i]);
		}
		ll max=1,tg=0;
		for(int i=0;i<k;i++)
		{
			max=1;
			for(int j=i;j<k;j++)
			{
			
				max*=data[j];
				if(max>tg)
					tg=max;
			}
		}
		printf("Case #%lld: The maximum product is %lld.\n\n",++a,tg);
	}
	return 0;
}
