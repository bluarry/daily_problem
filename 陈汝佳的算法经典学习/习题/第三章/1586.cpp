#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
//	freopen("D:\\1.in","r",stdin);
	char mec[100];
	double sum=0;
	int C,H,O,N;
	int T,len;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",mec);
		len=strlen(mec);
		C=0,H=0,O=0,N=0;
		int i,j,k;
		for(i=0;i<len;i=j)
		{
			if(isalpha(mec[i]))
			{
				int times=0;
				for(j=i+1,k=1;isdigit(mec[j]);j++)
				{
						if(2==k) times=times*10+(mec[j]-'0');
						else
						{times+=(mec[j]-'0');k++;}
				}

				if(j==i+1) times+=1;
				
				if(mec[i] == 'C')
					C+=times;
				else if(mec[i] == 'H')
					H+=times;
				else if(mec[i]=='O') O+=times;
				else if(mec[i]=='N') N+=times;
			}
		}
		printf("%.3lf\n", 12.01*C+1.008*H+O*16.00+14.01*N );



	}

	return 0;
}
