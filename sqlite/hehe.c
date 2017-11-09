#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	/*
	 *c语言中注意区分sizeof和strlen对字符指针的作用
	 */
	char* name="ID";
	char* sql1="SELECT ";
	char* sql2=" FROM COMPANY;";

	int len1=strlen(name),len2=strlen(sql1),len3=strlen(sql2);


	char* sql=(char *)malloc((len1+len2+len3)*sizeof(char));  	
	
	memcpy(sql,sql1,strlen(sql1));
	memcpy(sql+len2-1,name,strlen(name));
	memcpy(sql+len2-1+strlen(name)-1,sql2,strlen(sql2));	
	
	
	puts(sql);
	
	
	free(sql);
	return 0;
}							
