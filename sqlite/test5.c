#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlite3.h>
int main()
{
	sqlite3 *db;

	int rc=sqlite3_open("hehe.db",&db);
	if(rc){
		fprintf(stderr,"打开失败: %s\n",sqlite3_errmsg(db));
		exit(1);
	}
	
	char* sql="SELECT * FROM COMPANY;";
	sqlite3_stmt *stmt;
	const char *tail;

	rc=sqlite3_prepare_v2(db,sql,-1,&stmt,&tail);
	if(rc!=SQLITE_OK){
		fprintf(stderr,"失败: %s\n",sqlite3_errmsg(db));
	}
	
	rc=sqlite3_step(stmt);
	int ncols=sqlite3_column_count(stmt);
	for(int i=0;i<ncols;i++) fprintf(stdout,"%s ",sqlite3_column_name(stmt,i));
	fprintf(stdout,"\n");
	rc=sqlite3_step(stmt);

/*	fprintf(stdout,"ID= %d\n",sqlite3_column_int(stmt,0));
	const char* name=sqlite3_column_text(stmt,1);
	fprintf(stdout,"name=%s\n",name);
	
*/	
	
	sqlite3_finalize(stmt);
	//关闭
	sqlite3_close(db);
	return 0;
}
