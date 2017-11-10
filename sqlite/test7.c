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
	
	
	
	sqlite3_close(db);
	return 0;
}
