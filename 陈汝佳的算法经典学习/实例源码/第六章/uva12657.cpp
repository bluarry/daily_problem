#define LOCAL
#include <cstdio>
#include <cstring>
#define maxn 100000+5
int n,left[maxn],right[maxn];
void swap(int& a,int& b);
void link(int L,int R);
int main()
{
	#ifdef LOCAL
	freopen("D:\\1.in","r",stdin);
	#endif
	int m,kase=0;
	while(scanf("%d%d",&n,&m)==2){
		for(int i=1;i<=n;i++)//初始化静态链表数组
		{
			left[i]=i-1;
			right[i]=(i+1) % (n+1);
		}
		right[0]=1; left[0]=n;
		int op,X,Y,inv=0; //op记录当前什么操作,X,Y记录当前操作的俩元素，inv记录当前是什么顺序

		while(m--)
		{
			scanf("%d",&op);
			if(op==4) inv=!inv;
			else{
				scanf("%d%d",&X,&Y);
				if(op==3 && right[Y]==X) swap(X,Y);  //若输入的结点开始的结点在第二结点的右边，直接交换就行
				if(op!=3 && inv) op=3-op;  //若交换过，操作相反即可
				if(op==1 && X==left[Y]) continue;
				if(op==2 && Y==right[X]) continue;


				int LX=left[X],RX=right[X],LY=left[Y],RY=right[Y];
				if(op==1){
					link(LX,RX); //先去掉x
					link(LY,X);	//把x接到y的左边
					link(X,Y);	//把x和y链接
				}else if(op==2){
					link(LX,RX); //先去掉x
					link(Y,X);	//把x接到y的右边
					link(X,RY);	//最后再把x与y的右边接上
				}else if(op==3){
					if(right[X]==Y){	//若x，y相邻并且x在y的右边
						link(LX,Y);link(Y,X);link(X,RY);	
					}
					else{
						link(LX,Y);link(Y,RX);link(LY,X);link(X,RY);
					}
				}
			}
		}
		int b=0;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			b=right[b];
			if(i%2==1)
			{
				ans+=b;
			}
		}

		if(inv && n%2==0) ans= (long long )n*(n+1)/2 - ans; //若是求逆过,则结果应该是另一部分
		printf("Case %d: %lld\n",++kase,ans);
	}
	return 0;
}


void link(int L,int R){
	right[L]=R;
	left[R]=L;
}
void swap(int& a,int& b){
	int tem=a;
	a=b;
	b=a;
}