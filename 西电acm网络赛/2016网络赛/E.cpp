#include <stdio.h>
#include <string.h>
int main()
{
	 char A[100010]={'\0'},B[100010]={'\0'};
	 int i=0,j=0,k=0,time[26]={0},len_A=0,len_B=0,flag=0;
	 while(scanf("%s%s",&A,&B) != EOF)
	 {
	 	i=0,j=0,k=0,len_A=0,len_B=0,flag=0;
	 		for(j=0;j<26;j++)time[j]=0;
		 len_A=strlen(A);
		 len_B=strlen(B);
		 for(i=0;i<len_B;i++)
		 {
			 time[B[i]-'a']++;
		 }
		 for(i=0;i<len_A;i++)
		 {
			 if(time[A[i]-'a']==0)
			 {
			 	printf("%c",A[i]);
			 	flag=1;
			 }
		 }
		 if(flag==0)printf("EMPTY");
		printf("\n");
	 }
	return 0;
}
