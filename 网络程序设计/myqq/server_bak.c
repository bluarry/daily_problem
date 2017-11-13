#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
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
int check(MSG *msg)		//判断用户名是否已经注册
{
	FILE *fp=fopen("userdata.dat","a+");
	char buff[100];
	char name[40];
	while(!feof(fp))
	{
		fscanf(fp,"%s ",name);
		for(int i=0;i<=3;i++)
			i!=2?fscanf(fp,"%s ",buff):fscanf(fp,"%s",buff);
		if(strcmp(name,msg->name)==0)
		{
			return 0;
		}
	}
	return 1;
}
int regist(MSG* msg)
{
	FILE *fp=fopen("userdata.dat","a+");
	if(fp==NULL) return 0;

	if(check(msg))
	{
		msg->status=NOTLOGIN;
		fprintf(fp, "%s %s %s %d %d\n",msg->name,msg->password,
		inet_ntoa(msg->addr.sin_addr),ntohs(msg->addr.sin_port),msg->status );
		fclose(fp);
		return 1;
	}
		return 0;
}
int check_password(MSG* msg) //登录使用的
{
		FILE *fp=fopen("userdata.dat","rw+");

		if(fp==NULL) return 0;


		char name[40],password[10],buff[40];
		while(!feof(fp)){
		fscanf(fp,"%s %s ",name,password);

		char c='\0';
		while(c!='\n'&& !feof(fp))
			fscanf(fp,"%c",c);

		if(0==strcmp(name,msg->name)&& 0==strcmp(password,msg->password))
		{
			msg->status=LOGIN;
			fprintf(fp, "%d\n",LOGIN);
			fclose(fp);
			return 1;
		}
	}
	fclose(fp);
	return 0;
}
