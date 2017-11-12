#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlite3.h>


int main()
{
	sqlite3 *db;

	int rc=sqlite3_open("hehe.db",&db);
	
	if(rc!=SQLITE_OK)
		fprintf(stderr,"Sql open Error: %s\n",sqlite3_errmsg(db));
	
	
	char* sql="INSERT INTO COMPANY VALUES(?,?,?,?,?);";	
	sqlite3_stmt* stmt;
	char* tail;
	sqlite3_prepare_v2(db,sql,strlen(sql),&stmt,NULL);
	sqlite3_bind_int(stmt,1,12);
	sqlite3_bind_text(stmt,2,"test",strlen("test"),NULL);
	sqlite3_bind_int(stmt,3,-10);
	sqlite3_bind_text(stmt,4,"Mars",strlen("Mars"),NULL);
	sqlite3_bind_double(stmt,5,10000.12);	
	
	sqlite3_step(stmt);
	

	sqlite3_finalize(stmt);
	sqlite3_close(db);
	return 0;
}
