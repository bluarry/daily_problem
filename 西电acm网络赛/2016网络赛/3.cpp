#include <stdio.h>
int strlen(char sum[]);
int main()
{
	int line=0,i=0,j=0,k=0,flag_1=0,flag_2=0;
	int times=0,te_1=0;
	int len;
	char sum[30000]={"\0"},he[8]="wanshen",tem[8]={"\0"};
	fflush(stdin);
	while(scanf("%d",&line)!=EOF)
	{
		j=0;k=0;
		times=0;te_1=0;
		while(line--)
		{
			i=0;j=0;k=0;
			scanf("%s",&sum);
			len=strlen(sum);
			while(te_1&&te_1<=7)										
			{
				if(sum[i]==he[te_1])
				{
					tem[te_1]=he[te_1];
					te_1++;
					i++;
					
					if(te_1==7){times++;break;}
				}
				else 
				{
						te_1=0;
						break;
				}
			}
			for(i=0;i<len-6;i++)
			{
				j=i;
				while(1)
				{
					if(sum[j]==he[k]&&k<7)
					{
						j++;
						k++;
						if(k==7)
						{	i=j-2;
							times++;break;
						}
					}
					else 
					{
						k=0;
						break;
					}
				}
			}
			if(i!=len-6)
			i++;
			for(te_1=0;i<len;i++)
			{
					if(sum[i]==he[te_1])
					{
						tem[te_1]=he[te_1];
						te_1++;
					}		
					else if(sum[i]!=he[te_1])
					{
							continue;
					}
					else if(i==len&&te_1==0)
					{
						te_1=0;
						break;
					}

			}
		}
		printf("%d\n",times);
		
	}
	return 0;
}
int strlen(char sum[])
{
	int i=0;
	for(i=0;sum[i]!='\0';i++)
	;
	
	return i;
	
}
