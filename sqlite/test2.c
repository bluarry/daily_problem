#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include <string.h>

/**
 * data 为sqlite3_exec()的第四个参数
 * argc 为列的个数
 * argv 表示列的字符数组
 * azColName代表了列的名称
 *
 * 该函数每得到一条记录就回调一次
 */
int indexs=0;
static int callback(void *Data, int argc, char **argv, char **azColName){
	   int i;
	   for(i=0; i<argc; i++){
	//	strcpy((char *)Data+(indexs++),argv[i]);	
		  printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	   }
	   printf("\n");
	   return 0;
}

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
	
	
	//char* name="ID";
	
	char name[1024];
	scanf("%s",&name);
	
	char* sql1="SELECT ";
	char* sql2=" FROM COMPANY;";
	char* sql=(char *)malloc(sizeof(char)*(strlen(name)+strlen(sql1)+strlen(sql2)));
      	
	memcpy(sql,sql1,strlen(sql1));
	memcpy(sql+strlen(sql1),name,strlen(name));
	memcpy(sql+strlen(sql1)+strlen(name),sql2,strlen(sql2));	
	
	puts(sql);
	

	char *zErrMsg=NULL;
	char *data="callback called";
	rc=sqlite3_exec(db,sql,callback,(void *)data ,&zErrMsg);
	if(rc != SQLITE_OK){
		fprintf(stderr,"SQL ERROR : %s\n",zErrMsg);
		sqlite3_free(zErrMsg);
	}else{
		fprintf(stdout,"查询成功 !\n");
	}
	
/*	
	sqlite3_stmt * stat;
	char name1[]="name";
	rc=sqlite3_prepare(db,"SELECT ? FROM COMPANY;",-1,&stat,0);
	sqlite3_bind_text(stat,0,name1,strlen(name1),0);
	sqlite3_step(stat);
*/

//	for(int i=0;i<indexs;i++)
//		printf("%c \n",data[i]);
	
	
	free(sql);
	//free(data);
	//关闭链接
	sqlite3_close(db);
	return 0;
}
