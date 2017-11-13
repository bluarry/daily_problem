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
				printf("%s 登录成功 \n",msg.name );
			}else{
				sprintf(buff,"登录失败(用户名或密码错误)\n");
				sendto(sev_fd,buff,sizeof(buff),0,(struct sockaddr *)&client_addr,lenn);
				printf("%s 登录失败 \n",msg.name );
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
	if(rc!=SQLITE_OK){
		char* creat_sql="CREATE TABLE USERDATA("\
						"name TEXT NO NULL UNIQUE,"\
						"password TEXT NOT NULL,"\
						"ip TEXT,"\
						"port INT CHECK(port>0),"\
						"status INT CHECK(status >= 999995 AND status <=999998));";
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
}
int regist(MSG* msg)
{
	sqlite3 *db;
	//打开数据库
	int rc=sqlite3_open("users.db",&db);
	if(rc!=SQLITE_OK){
		ERR_EXIT(sqlite3_errmsg(db));
		sqlite3_close(db);
		return 0;
	}
	sqlite3_stmt* stmt;
	char* insert_sql="INSERT INTO USERDATA VALUES(?,?,?,?,?);";
	sqlite3_prepare_v2(db,insert_sql,-1,&stmt,NULL);

	msg->status=NOTLOGIN;
	sqlite3_bind_text(stmt,1,msg->name,strlen(msg->name),NULL);
	sqlite3_bind_text(stmt,2,msg->password,strlen(msg->password),NULL);
	sqlite3_bind_text(stmt,3,inet_ntoa(msg->addr.sin_addr),strlen(inet_ntoa(msg->addr.sin_addr)),NULL);
	sqlite3_bind_int(stmt,4,ntohs(msg->addr.sin_port));
	sqlite3_bind_int(stmt,5,msg->status);

	rc=sqlite3_step(stmt);

	sqlite3_finalize(stmt);
	sqlite3_close(db);


	if(rc==SQLITE_DONE){
		return 1;
	}
	//判断是否插入成功
	return 0;
}
int check_password(MSG* msg) //登录使用的
{
	sqlite3* db;
	int rc=sqlite3_open("users.db",&db);
	if(rc!=SQLITE_OK){
		ERR_EXIT(sqlite3_errmsg(db));
		sqlite3_close(db);
		return 0;
	}
	sqlite3_stmt* stmt;
	char* getpass="SELECT password FROM USERDATA WHERE name=?;";
	rc=sqlite3_prepare_v2(db,getpass,-1,&stmt,NULL);
	if(rc!=SQLITE_OK){
		ERR_EXIT(sqlite3_errmsg(db));
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
	fprintf(stdout,"%s\n",pass);
	sqlite3_finalize(stmt);
	if(rc==SQLITE_ROW){
		sqlite3_stmt* stmts;
		char* up_status="UPDATE USERDATA SET status=? WHERE name=?;";
		rc=sqlite3_prepare_v2(db,up_status,-1,&stmts,NULL);
		sqlite3_bind_int(stmts,1,LOGIN);
		sqlite3_bind_text(stmts,2,msg->name,strlen(msg->name),NULL);
		rc=sqlite3_step(stmts);
		sqlite3_finalize(stmts);
		fprintf(stdout, "rc = %d\n",rc );
		if(rc==SQLITE_DONE){
			sqlite3_close(db);
			return 1;
		}else{
			sqlite3_close(db);
			return 0;
		}
	}
	sqlite3_close(db);
	return 0;

}
