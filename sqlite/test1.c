#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <string.h>

/*
static int callback(void *NotUsed, int argc, char **argv, char **azColName){
	   int i;
	   for(i=0; i<argc; i++){
		 printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	   }
	   printf("\n");
	   return 0;
}
*/
/**
 *sqlite3 c语言的使用api调用来操作数据库，示例
 *
 */
int main()
{
	sqlite3 * db;

	int rc=sqlite3_open("hehe.db",&db);
	
	if(rc){
		fprintf(stderr,"数据库打开失败：%s \n",sqlite3_errmsg(db));
		exit(1);
	}else{
		fprintf(stderr,"数据库打开成功\n");
	}
	
	char* sql=	"CREATE TABLE COMPANY("  \
		        "ID INT PRIMARY KEY     NOT NULL," \
		        "NAME           TEXT    NOT NULL," \
		        "AGE            INT     NOT NULL," \
		        "ADDRESS        CHAR(50)," \
		        "SALARY         REAL );";
//	char* sql2="DROP TABLE COMPANY;";	
	
	char *zErrMsg=NULL;
	rc=sqlite3_exec(db,sql,NULL,NULL ,&zErrMsg);
	if(rc != SQLITE_OK){
		fprintf(stderr,"SQL ERROR : %s\n",zErrMsg);
		sqlite3_free(zErrMsg);
	}else{
		fprintf(stdout,"Table Create successfully!\n");
	}
	
	
	/* 删除表
	rc=sqlite3_exec(db,sql2,NULL,NULL ,&zErrMsg);
	if(rc != SQLITE_OK){
		fprintf(stderr,"SQL ERROR : %s\n",zErrMsg);
		sqlite3_free(zErrMsg);
	}else{
		fprintf(stdout,"Table Delete successfully!\n");
	}

	*/

	char* sql_ins = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
	         	"VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
		         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
			 "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
			 "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
			 "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
			 "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
			 "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";
	

	rc=sqlite3_exec(db,sql_ins,NULL,NULL ,&zErrMsg);
	if(rc != SQLITE_OK){
		fprintf(stderr,"SQL ERROR : %s\n",zErrMsg);
		sqlite3_free(zErrMsg);
	}else{
		fprintf(stdout,"Table Insert successfully!\n");
	}



	//关闭链接
	sqlite3_close(db);
	return 0;
}
