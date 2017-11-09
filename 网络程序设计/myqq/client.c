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


int STATUS=NOTREGISTED;


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
    struct sockaddr_in addr; /*客户端的ip，客户端不发，在服务端自己设置*/
	int status;		//用户的状态
}MSG;
int MSG_size;
char loginanme[30];

void show_option1(MSG*); //显示可选
void show_option2(MSG*);
void regist(int ,struct sockaddr_in*,MSG*); //用户注册
void login(int ,struct sockaddr_in*,MSG*);



int  main(int argc, char const *argv[]) {
    if(argc != 2){
		fprintf(stderr, "Usage: %s [portnumber](server port)\n", argv[0]);
		exit(1);
	}
	int PORT = atoi(argv[1]);
    MSG msg;
    MSG_size=sizeof(msg);
    bzero(&msg,MSG_size);




    int cli_fd=socket(AF_INET,SOCK_DGRAM,0);
    if(cli_fd<0){
        ERR_EXIT("socket 创建失败");
    }

    struct sockaddr_in servaddr;
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=PORT;
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");

    while(1)
    {

        if(STATUS==NOTREGISTED || STATUS==NOTLOGIN || STATUS==LOGOUT)
            show_option1(&msg);
		else if(STATUS==LOGIN)
			show_option2(&msg);

		if(msg.type==0)
		{
			close(cli_fd);
			exit(0);
		}
        else if(msg.type==1)
        {
            regist(cli_fd,&servaddr,&msg);
			system("clear");
            continue;
        }else if(msg.type==2)
        {
			login(cli_fd,&servaddr,&msg);
			system("clear");
			continue;
        }
		else if(msg.type==3){//3.查询在线用户

			printf("查询在线用户\n"); sleep(1.5);
			system("clear");
			continue;
		}
		else if(msg.type==4){// 4.聊天服务
			printf("聊天服务\n"); sleep(1.5);
			system("clear");
			continue;
		}
		else if(msg.type==5){//5.用户退出
			printf("用户退出\n"); sleep(1.5);
			system("clear");
			continue;
		}
		else if(msg.type==6){// 6. 文件传输
			printf("文件传输\n"); sleep(1.5);
			system("clear");
			continue;
		}
		else if(msg.type==7){//7.文件断点传输
			printf("文件断点传输\n"); sleep(1.5);
			system("clear");
			continue;
		}

    }
    return 0;
}
void show_option1(MSG * msg){//1.用户注册  2.用户登录  3.用户退出  4. 在线用户查询
    system("clear");
    printf("***********************仿qq聊天程序******************************\n" );
    printf("*****      1.用户注册               2.用户登录                ****\n" );
	printf("***** 	               0.退出程序                           ****\n" );
    printf("*************************End************************************\n" );
    printf("选择服务 : ");
	scanf("%d",& msg->type);
	if(msg->type >2|| msg->type < 0) printf("无该选项，请重新输入\n");
}
void show_option2(MSG *msg){//3.查询在线用户  4.聊天服务  5.用户退出  6. 文件传输  7.文件断点传输
    system("clear");
	printf("\nHELLO %s , You have login!! Enjoy yourself!! \n\n",loginanme);
    printf("***********************仿qq聊天程序******************************\n" );
    printf("*****      1.查询在线用户               2.聊天服务            ****\n" );
    printf("*****      2.用户退出               	4.文件传输            ****\n" );
    printf("*****                   5.文件断点传输                       ****\n" );
	printf("***** 	                0.退出程序                            ****\n" );
    printf("*************************End************************************\n" );
    printf("选择服务 : ");
	scanf("%d", & msg->type);
	if(msg->type >5|| msg->type <0) printf("无该选项，请重新输入\n");
	else if(msg->type) msg->type+=2;
}

void regist(int fd, struct sockaddr_in *servaddr,MSG *msg){
    system("clear");
    printf("*****************注册************\n");
    printf("请输入用户名 : ");
    scanf("%s",msg->name);
    printf("请输入密码(最长8位) : " );
    scanf("%s",msg->password);
	msg->status=NOTREGISTED;

    int addrlen=sizeof(struct sockaddr);
    sendto(fd,msg,MSG_size,0,(struct sockaddr *)servaddr,addrlen);

    char buff[1024];
    memset(buff,0,sizeof(buff));

    int size=recvfrom(fd,buff,1024,0,NULL,NULL);
    if(size>0)
    {
        fputs(buff,stdout);
        STATUS=NOTLOGIN;
    }
    else
    {
        printf("通信失败\n");
    }
	sleep(1.5);
    return ;
}
void login(int fd, struct sockaddr_in *servaddr,MSG* msg){
	system("clear");
	printf("****************** 登录 *****************\n" );
	char name[40],password[10];
	printf("用户名 ： " );	scanf("%s",name);
	printf("密码 : " );	scanf("%s",password);

	strcpy(msg->name,name);
	strcpy(msg->password,password);

	int addrlen=sizeof(struct sockaddr);
    sendto(fd,msg,MSG_size,0,(struct sockaddr *)servaddr,addrlen);

	char buff[1024],str[1024];
	memset(buff,0,sizeof(buff));
	sprintf(str, "登录成功\n");
	int size=recvfrom(fd,buff,1024,0,NULL,NULL);

	if(size > 0)
	{
		fprintf(stdout, "%s\n", buff);
		if(0==strcmp(str,buff))
		{
			strcpy(loginanme,msg->name);
			STATUS=LOGIN;
		}
	}else
	{
		printf("连接异常\n" );
	}

	sleep(1.5);
	return ;
}
