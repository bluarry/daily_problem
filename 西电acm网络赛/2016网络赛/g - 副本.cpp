#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n=0,k=0,i=0,j=0,m=0,qq,tt;
	long int temp=0,files[1010]={0},times[1010]={0},time=0;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
			 temp=0;
			tt=0;time=0;
			for(i=0;i<n;i++)
			{
				scanf("%d",&files[i]);
			}
	
		for(i=0;i<n;i++)				
			for(j=i;j<n-1;j++)
			{
				if(files[i]>files[j])
				{
					temp=files[i];
					files[i]=files[j];
					files[j]=temp;
				}
			}    
			
	
			if(n<=k) 
			{	
				for(i=0;i<n;i++)
						time+=files[i];
					printf("%d\n",time);
					continue;
			}	
			if((n-k)%(k-1)==0)
			for(j=0;j<k;j++) 
					{times[tt]+=files[j];}
			else 
				for(j=0;j<(n-k)%(k-1)+1;j++) 
					{times[tt]+=files[j];}
				tt++;
			if((n-k)%(k-1) == 0)
			for(i=j,qq=0;qq<((n-k)/(k-1));qq++)
			{
				for(m=0;m<k-1;m++)
					temp+=files[i+m];
				times[tt]=times[tt-1]+temp;
				tt++;
				i=i+m;
				temp=0;
			}
			else 
			{
				n=n-(n-k)%(k-1)-1;
				for(i=j,qq=0;qq<((n)/(k-1));qq++)
					{
						for(m=0;m<k-1;m++)
							temp+=files[i+m];
						times[tt]=times[tt-1]+temp;tt++;
						i=i+m;
						temp=0;
					}
			}
			
				for(i=0,time=0;i<tt;i++)
			{
				time+=times[i];
				printf("times[%d]=%ld\n",i,times[i]);
			}
			printf("%ld\n",time);
		
		
		
				for(i=0;i<n;i++)
			{
				files[i]=0;
			}
					for(i=0,time=0;i<tt;i++)
			{
				times[i]=0;}
	}
	return 0;
}
