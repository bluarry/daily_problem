#include <stdio.h>
int iszhuzhi(int a,int b);
int jiecheng(int n);
int main()
{
	int a[10];
	int table[10][10]={0};
	while(scanf("%d%d%d%d%d%d%d%d%d",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9])  != EOF )
	{
		int i=0,j=0,m=0,n=0,times=0,ti4=0,ti2=0;
		for(i=1;i<=9;i++)
			for(j=1;j<=9;j++)
			{
				if(i==j) continue;
				table[i][j]=iszhuzhi(a[i],a[j]);
			}
			for(m=0;m<10;m++)
			{
				times=0;
				for(n=0;n<10;n++)
				{
					if(table[m][n]==1)
					times++;
				}
				if(times>=4) ti4++;
				if(times>=2&&times<4)ti2++;
			}
		printf("ti4 %d ti2 %d\n",ti4,ti2);
			
		if(ti2+ti4>=5&&ti4>=1&&ti2>=4)
			printf("%d\n",ti4*jiecheng(4)*jiecheng(9-5));
		else 	
		printf("0\n");
		
		
		
		
		
		
	}		
	return 0;
}
int iszhuzhi(int a,int b)
{
	int temp;
	while(b!=0){
			temp=b;
			b=a%b;
			a=temp;
			}
	if(a==1)
				return 1;
		else
				return 0;
}
int jiecheng(int n)
{
	int i=0,sum=1;
	if(n==0) return 1;
	for(i=0;i<n;i++)
	sum*=i;
	return sum;
}
