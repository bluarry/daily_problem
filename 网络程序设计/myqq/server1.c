#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sqlite3.h>

#define NOTREGISTED 999996
#define  LOGIN  999998
#define  LOGOUT 999997
#define NOTLOGIN 999995


#define ERR_EXIT(m) \
	do \
	{ \
		perror(m); \
		exit(EXIT_FAILURE); \
	} while(0)


//客户端与服务端通信数据类型
typedef struct MSG{
    int type;       /*消息的类型 1.用户注册  2.用户登录  3.用户退出  4. 在线用户查询 */
    char name[30];
    char password[10];
    struct sockaddr_in addr;
	int status;

}MSG;
int MSG_size;


int regist(MSG*);
int check_password(MSG*);
void init_sql();
int try_logout(MSG* msg);
void  reolimem(char buff[][30],int *num);
void  reoflimem(char buff[][30],int *num);
int getcli_t(MSG *msg,char *res);
int setcli_t(MSG *msg);
int getcliistus(MSG* msg);
int  main(int argc, char const *argv[]) {
    if(argc != 2){
		fprintf(stderr, "Usage: %s [portnumber](server port)\n", argv[0]);
		exit(1);
	}
    //初始化各变量
    int PORT = atoi(argv[1]);
    MSG msg;
    MSG_size=sizeof(msg);
    bzero(&msg,MSG_size);

    int sev_fd=socket(AF_INET,SOCK_DGRAM,0);//udp
    if(sev_fd<0)
    {
        ERR_EXIT("创建socket失败");
    }

    struct sockaddr_in servaddr;
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=PORT;
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");

    int opt = 1;
	// sockfd为需要端口复用的套接字
   setsockopt(sev_fd, SOL_SOCKET, SO_REUSEADDR, (const void *)&opt, sizeof(opt));

   if(bind(sev_fd,(struct sockaddr *)& servaddr,sizeof(servaddr)) < 0){
            ERR_EXIT("bind 错误");
    }

    struct sockaddr_in client_addr;
    socklen_t lenn=sizeof(client_addr);
	init_sql();
    while(1)
    {
        ssize_t size=recvfrom(sev_fd,&msg,sizeof(msg),0,
               (struct sockaddr *)&client_addr,&lenn);
		if(size <=0) continue;
		msg.addr=client_addr;
        if(msg.type==1) //注册
        {
			char buff[1024];
			bzero(buff,sizeof(buff));
            if(regist(&msg))
			{

				sprintf(buff,"注册成功\n");
				sendto(sev_fd,buff,sizeof(buff),0,(struct sockaddr *)&client_addr,lenn);
				printf("%s 注册成功\n",msg.name);
			}
			else {
				sprintf(buff,"注册失败(用户名已被注册)\n");
				sendto(sev_fd,buff,sizeof(buff),0,(struct sockaddr *)&client_addr,lenn);
				printf("%s 注册失败\n",msg.name );
			}
        }else if(msg.type==2)
		{
			char buff[1024];
			bzero(buff,sizeof(buff));
			if(check_password(&msg))
			{
				sprintf(buff,"登录成功\n");
				sendto(sev_fd,buff,sizeof(buff),0,(struct sockaddr *)&client_addr,lenn);
				sleep(0.5);//控制先后次序
				sendto(sev_fd,&msg.addr,sizeof(msg.addr),0,(struct sockaddr *)&client_addr,lenn);
				printf("%s 登录成功 \n",msg.name );
			}else{
				sprintf(buff,"登录失败(用户名或密码错误)\n");
				sendto(sev_fd,buff,sizeof(buff),0,(struct sockaddr *)&client_addr,lenn);
				printf("%s 登录失败 \n",msg.name );
			}
		}else if(msg.type==3){
			char buff[1024];
			bzero(buff,sizeof(buff));
			if(try_logout(&msg)){
				sprintf(buff,"登出成功\n");
				sendto(sev_fd,buff,sizeof(buff),0,(struct sockaddr *)&client_addr,lenn);
				printf("%s 登出成功\n",msg.name);
			}else{
				sprintf(buff,"登出失败(用户正忙)\n");
				sendto(sev_fd,buff,sizeof(buff),0,(struct sockaddr *)&client_addr,lenn);
				printf("%s 登出失败\n",msg.name);
			}
		}else if(msg.type==4){//在线用户
				char buff[50][30];
				int num=0;
				reolimem(buff,&num);
				for(int i=0;i<num;i++)
				{
					sendto(sev_fd,buff[i],strlen(buff[i]),0,(struct sockaddr *)&client_addr,lenn);
				}
				//结束帧
				sendto(sev_fd,NULL,0,0,(struct sockaddr *)&client_addr,lenn);
		}else if(msg.type==5){//在线用户
				char buff[50][30];
				int num=0;
				reoflimem(buff,&num);
				for(int i=0;i<num;i++)
				{
					sendto(sev_fd,buff[i],strlen(buff[i]),0,(struct sockaddr *)&client_addr,lenn);
				}
				//结束帧
				sendto(sev_fd,NULL,0,0,(struct sockaddr *)&client_addr,lenn);
		}else if(msg.type==6){ //查询cli_t并返回
				char buff[50];
				memset(buff,0,sizeof(buff));
				int ret=getcli_t(&msg,buff);
				if(ret){
					// fprintf(stdout, "%s\n",buff);
					sendto(sev_fd,buff,sizeof(buff),0,(struct sockaddr *)&client_addr,lenn);
				}else{
					sendto(sev_fd,NULL,0,0,(struct sockaddr *)&client_addr,lenn);
				}
		}else if(msg.type==7){
				char buff[1024];
				memset(buff,0,sizeof(buff));
				if(setcli_t(&msg)){
					sprintf(buff,"设置成功\n");
					sendto(sev_fd,buff,sizeof(buff),0,(struct sockaddr *)&client_addr,lenn);
				}else{
					sendto(sev_fd,NULL,0,0,(struct sockaddr *)&client_addr,lenn);
				}
		}else if(msg.type==8){
			if(getcliistus(&msg)){
				sendto(sev_fd,&msg,sizeof(MSG),0,(struct sockaddr *)&client_addr,lenn);
			}else{
				sendto(sev_fd,NULL,0,0,(struct sockaddr *)&client_addr,lenn);
			}
		}
    }
    return 0;
}
/*************************************函数实现***************************************************************/
void init_sql(){
	sqlite3 *db;
	//打开数据库
	int rc=sqlite3_open("users.db",&db);
	if(rc!=SQLITE_OK){
		ERR_EXIT(sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
	}

	char* sql_check="SELECT * FROM USERDATA;";

	char* check_err=NULL;
	rc=sqlite3_exec(db,sql_check,NULL,NULL,&check_err);
	//fprintf(stdout,"%d\n",rc);
	if(rc!=SQLITE_OK){
		char* creat_sql="CREATE TABLE USERDATA("\
						"name TEXT NO NULL UNIQUE,"\
						"password TEXT NOT NULL,"\
						"ip TEXT,"\
						"port INT CHECK(port>0),"\
						"status INT CHECK(status >= 999995 AND status <=999998),"
						"cli_t TEXT CHECK(cli_t IN ('0','1')));";
		char* creat_err=NULL;
		rc=sqlite3_exec(db,creat_sql,NULL,NULL,&creat_err);
		if(rc!=SQLITE_OK)
		{
			ERR_EXIT(creat_err);
			sqlite3_free(creat_err);
			sqlite3_close(db);
			printf("初始化失败\n");
			exit(1);
		}
	}
	sqlite3_close(db);
}
int regist(MSG* msg)
{
	sqlite3 *db;
	//打开数据库
	int rc=sqlite3_open("users.db",&db);
	if(rc!=SQLITE_OK){
		fprintf(stdout, "%s\n",sqlite3_errmsg(db) );
		sqlite3_close(db);
		return 0;
	}
	sqlite3_stmt* stmt;
	char* insert_sql="INSERT INTO USERDATA VALUES(?,?,?,?,?,?);";
	sqlite3_prepare_v2(db,insert_sql,-1,&stmt,NULL);
	msg->status=NOTLOGIN;
	sqlite3_bind_text(stmt,1,msg->name,strlen(msg->name),NULL);
	sqlite3_bind_text(stmt,2,msg->password,strlen(msg->password),NULL);
	sqlite3_bind_text(stmt,3,inet_ntoa(msg->addr.sin_addr),strlen(inet_ntoa(msg->addr.sin_addr)),NULL);
	sqlite3_bind_int(stmt,4,ntohs(msg->addr.sin_port));
	sqlite3_bind_int(stmt,5,msg->status);
	sqlite3_bind_text(stmt,6,"0",strlen("0"),NULL);

	rc=sqlite3_step(stmt);

	sqlite3_finalize(stmt);
	sqlite3_close(db);


	if(rc==SQLITE_DONE){
		return 1;
	}
	//判断是否插入成功
	return 0;
}
int update_ipandport(MSG* msg){
	sqlite3 *db;
	int rc=sqlite3_open("users.db",&db);
	if(rc!=SQLITE_OK){
		fprintf(stdout, "%s\n",sqlite3_errmsg(db) );
		sqlite3_close(db);
		return 0;
	}
	//用MSG的ip和port更新数据库
	sqlite3_stmt* stmt;
	char* update_sql="UPDATE USERDATA SET ip=?,port=? WHERE name=?;";
	rc=sqlite3_prepare_v2(db,update_sql,-1,&stmt,NULL);
	sqlite3_bind_text(stmt,1,inet_ntoa(msg->addr.sin_addr),strlen(inet_ntoa(msg->addr.sin_addr)),NULL);
	sqlite3_bind_int(stmt,2,ntohs(msg->addr.sin_port) );
	sqlite3_bind_text(stmt,3,msg->name,strlen(msg->name),NULL);

	rc=sqlite3_step(stmt);
	sqlite3_close(db);
	//fprintf(stdout, "rc = %d\n",rc );
	if(rc==SQLITE_DONE|| rc==SQLITE_ROW){
		return 1;
	}
	return 0;
}
int check_password(MSG* msg) //登录使用的
{
	sqlite3* db;
	int rc=sqlite3_open("users.db",&db);
	if(rc!=SQLITE_OK){
		fprintf(stdout, "%s\n",sqlite3_errmsg(db) );
		sqlite3_close(db);
		return 0;
	}
	sqlite3_stmt* stmt;
	char* getpass="SELECT password FROM USERDATA WHERE name=?;";
	rc=sqlite3_prepare_v2(db,getpass,-1,&stmt,NULL);
	if(rc!=SQLITE_OK){
		fprintf(stdout, "%s\n",sqlite3_errmsg(db) );
		sqlite3_close(db);
		return 0;
	}
	sqlite3_bind_text(stmt,1,msg->name,strlen(msg->name),NULL);
	rc=sqlite3_step(stmt);
	const char* pass=sqlite3_column_text(stmt,0);
	if(pass==NULL){
		sqlite3_finalize(stmt);
		sqlite3_close(db);
		return 0;
	}
	//fprintf(stdout,"%s\n",pass);
	sqlite3_finalize(stmt);
	if(rc==SQLITE_ROW && 0==strcmp(pass,msg->password)){
		sqlite3_stmt* stmts;
		char* up_status="UPDATE USERDATA SET status=? WHERE name=?;";
		rc=sqlite3_prepare_v2(db,up_status,-1,&stmts,NULL);
		sqlite3_bind_int(stmts,1,LOGIN);
		sqlite3_bind_text(stmts,2,msg->name,strlen(msg->name),NULL);
		rc=sqlite3_step(stmts);
		sqlite3_finalize(stmts);
		// fprintf(stdout, "rc = %d\n",rc );
		if(rc==SQLITE_DONE){
			sqlite3_close(db);
			if(update_ipandport(msg)){
				return 1;
			}
		}else{
			sqlite3_close(db);
			return 0;
		}
	}
	sqlite3_close(db);
	return 0;
}
//发现问题！！： 每个用户登录之后并没有退出
int try_logout(MSG* msg){
	sqlite3* db;
	int rc=sqlite3_open("users.db",&db);
	if(rc!=SQLITE_OK){
		fprintf(stdout, "%s\n",sqlite3_errmsg(db) );
		sqlite3_close(db);
		return 0;
	}
	sqlite3_stmt* stmts;
	char* logoutsql="UPDATE USERDATA SET status=? WHERE name=?;";

	rc=sqlite3_prepare_v2(db,logoutsql,-1,&stmts,NULL);

	sqlite3_bind_int(stmts,1,LOGOUT);
	sqlite3_bind_text(stmts,2,msg->name,strlen(msg->name),NULL);
	rc=sqlite3_step(stmts);

	sqlite3_finalize(stmts);

	if(rc==SQLITE_DONE){
		sqlite3_close(db);
		return 1;
	}else{
		sqlite3_close(db);
		return 0;
	}
}
//在线成员
void  reolimem(char buff[][30],int *num){
	sqlite3* db;
	int rc=sqlite3_open("users.db",&db);
	if(rc!=SQLITE_OK){
		fprintf(stdout, "%s\n",sqlite3_errmsg(db));
		sqlite3_close(db);
		return ;
	}
	sqlite3_stmt* stmts;
	char* onmesql="SELECT name FROM USERDATA WHERE status=?;";
	rc=sqlite3_prepare_v2(db,onmesql,-1,&stmts,NULL);
	sqlite3_bind_int(stmts,1,LOGIN);
	rc=sqlite3_step(stmts);
	while(rc==SQLITE_ROW){
		const char * result=sqlite3_column_text(stmts,0);
		//fprintf(stdout, "%s\n", result);
		strcpy(buff[(*num)++],result);

		rc=sqlite3_step(stmts);
	}
	sqlite3_finalize(stmts);
	sqlite3_close(db);
}
void  reoflimem(char buff[][30],int *num){
	sqlite3* db;
	int rc=sqlite3_open("users.db",&db);
	if(rc!=SQLITE_OK){
		fprintf(stdout, "%s\n",sqlite3_errmsg(db));
		sqlite3_close(db);
		return ;
	}
	sqlite3_stmt* stmts;
	char* onmesql="SELECT name FROM USERDATA WHERE status !=?;";
	rc=sqlite3_prepare_v2(db,onmesql,-1,&stmts,NULL);
	sqlite3_bind_int(stmts,1,LOGIN);
	rc=sqlite3_step(stmts);
	while(rc==SQLITE_ROW){
		const char * result=sqlite3_column_text(stmts,0);
		//fprintf(stdout, "%s\n", result);
		strcpy(buff[(*num)++],result);

		rc=sqlite3_step(stmts);
	}
	sqlite3_finalize(stmts);
	sqlite3_close(db);
}
int getcli_t(MSG *msg,char res[]){
	sqlite3 *db;
	int rc=sqlite3_open("users.db",&db);
	if(rc!=SQLITE_OK){
		fprintf(stdout, "%s\n",sqlite3_errmsg(db));
		sqlite3_close(db);
		return 0;
	}
	sqlite3_stmt* stmts;
	char* onmesql="SELECT cli_t FROM USERDATA WHERE name=?;";
	rc=sqlite3_prepare_v2(db,onmesql,-1,&stmts,NULL);
	sqlite3_bind_text(stmts,1,msg->name,strlen(msg->name),NULL);

	rc=sqlite3_step(stmts);
	if(rc==SQLITE_DONE || rc == SQLITE_ROW){
		const char* result=sqlite3_column_text(stmts,0);
		strcpy(res,result);
		sqlite3_finalize(stmts);
		sqlite3_close(db);
		return 1;
	}
	sqlite3_finalize(stmts);
	sqlite3_close(db);
	return 0;
}
int setcli_t(MSG *msg){
	sqlite3 *db;
	int rc=sqlite3_open("users.db",&db);
	if(rc!=SQLITE_OK){
		fprintf(stdout, "%s\n",sqlite3_errmsg(db));
		sqlite3_close(db);
		return 0;
	}
	sqlite3_stmt* stmts;
	char* onmesql="UPDATE USERDATA SET cli_t=? WHERE name=?;";
	rc=sqlite3_prepare_v2(db,onmesql,-1,&stmts,NULL);
	sqlite3_bind_text(stmts,1,msg->password,strlen(msg->password),NULL);
	sqlite3_bind_text(stmts,2,msg->name,strlen(msg->name),NULL);
	rc=sqlite3_step(stmts);
	if(rc==SQLITE_DONE){
		sqlite3_finalize(stmts);
		sqlite3_close(db);
		return 1;
	}
	sqlite3_finalize(stmts);
	sqlite3_close(db);
	return 0;
}
int getcliistus(MSG* msg){
	sqlite3 *db;
	int rc=sqlite3_open("users.db",&db);
	if(rc!=SQLITE_OK){
		fprintf(stdout, "%s\n",sqlite3_errmsg(db));
		sqlite3_close(db);
		return 0;
	}
	sqlite3_stmt* stmts;
	char* onmesql="SELECT ip,port FROM USERDATA WHERE name=?;";
	rc=sqlite3_prepare_v2(db,onmesql,-1,&stmts,NULL);
	sqlite3_bind_text(stmts,1,msg->name,strlen(msg->name),NULL);
	rc=sqlite3_step(stmts);
	if(rc==SQLITE_DONE || rc==SQLITE_ROW){
		fprintf(stdout, "%s: %d\n", sqlite3_column_text(stmts,0),sqlite3_column_int(stmts,1));
		msg->addr.sin_addr.s_addr=inet_addr(sqlite3_column_text(stmts,0));
		msg->addr.sin_port=htons(sqlite3_column_int(stmts,1)+1);
		sqlite3_finalize(stmts);
		sqlite3_close(db);
		return 1;
	}
	sqlite3_finalize(stmts);
	sqlite3_close(db);
	return 0;
}
