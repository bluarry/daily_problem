#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>


int main()
{
	sqlite3 * db;

	int rc=sqlite3_open("hehe.db",&db);

	if(rc){
		fprintf(stderr,"打开失败 ： %s\n",sqlite3_errmsg(db));
		exit(1);
	}

	char** result;
	char* sql="SELECT * FROM COMPANY;";
	int nrow;
	int ncolumn;
	char* zerrmsg;
	rc=sqlite3_get_table(db,sql,&result,&nrow,&ncolumn,&zerrmsg);	

	if(rc!=SQLITE_OK){
		fprintf(stderr,"执行失败: %s\n",sqlite3_errmsg(db));
	}

	printf("row=%d,col=%d\n",nrow,ncolumn);
	for(int i=0;i<ncolumn;i++)
		printf("%s\t\t",result[i]);
	puts("");
	for(int i=0;i<nrow;i++)
		for(int j=0;j<ncolumn;j++){
			j==ncolumn-1?printf("%s\n",result[(i+1)*ncolumn+j]):printf("%s\t\t",result[(i+1)*ncolumn+j]);
		}	
	sqlite3_close(db);
	sqlite3_free_table(result);
	
	return 0;
}
