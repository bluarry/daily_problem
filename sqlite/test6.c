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
	for(int i=0;i<ncols;i++) fprintf(stdout,"%s\t",sqlite3_column_name(stmt,i));
	fprintf(stdout,"\n");
	rc=sqlite3_step(stmt);
	while(rc==SQLITE_ROW){
		fprintf(stdout,"%d\t%s\t%d\t%s\t%.2lf\n",sqlite3_column_int(stmt,0),sqlite3_column_text(stmt,1),sqlite3_column_int(stmt,2)
							,sqlite3_column_text(stmt,3),sqlite3_column_double(stmt,4));
		rc=sqlite3_step(stmt);
	}
	
	sqlite3_finalize(stmt);
	//关闭
	sqlite3_close(db);
	return 0;
}
