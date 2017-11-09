#include <stdio.h>
#include <stdlib.h>

#include <sqlite3.h>
int main()
{
	sqlite3 *db;
	int rc=sqlite3_open("hehe.db",&db);
	//如果失败rc大于0
	if(rc){
		fprintf(stderr,"Can't open database:%s\n",sqlite3_errmsg(db));
		exit(1);
	}else
	{
		fprintf(stderr,"Opened databases successfully!\n");
	}
	if(sqlite3_close(db)){
		printf("关闭失败\n");
	}else{
		printf("关闭连接成功\n");
	}
	
	return 0;
}

