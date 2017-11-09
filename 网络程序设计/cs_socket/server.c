#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>


#define PORT 32767
#define DES "127.0.0.1"
#define BACKLOG 10
int main()
{

    /* 创建一个socket */
    int sockfd=0;
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd < 0){
        printf("创建socket失败\n");
        exit(1);
    }

    printf("socket 创建成功\n");

    /* 绑定服务器地址 */
    struct sockaddr_in serveraddr;
    struct sockaddr_in cilent_addr;

    bzero(&serveraddr,sizeof(serveraddr));
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(PORT);
    serveraddr.sin_addr.s_addr=inet_addr(DES);
    // serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);

    if(bind(sockfd,(struct sockaddr *) &serveraddr,sizeof(serveraddr))< 0){
        printf("绑定失败\n" );
        exit(1);
    }
    printf("本地绑定成功\n");
    /* 监听端口 */
    if(listen(sockfd,BACKLOG)<0){
        printf("监听失败\n");
        exit(1);
    }
    printf("端口监听成功\n");

    /* 接收 */
    socklen_t addr_len=sizeof(struct sockaddr_in);

    int cilent_fd=accept(sockfd, (struct sockaddr *) &cilent_addr,& addr_len);
    if(cilent_fd < 0){
        printf("接收错误\n" );
        exit(1);
    }
    printf("链接成功\n");
    char buff[1024];
    while(1){
        //接受
         ssize_t size=read(cilent_fd,buff,1024);
         if(size == 0){
            exit(0);
         }
         fputs(buff,stdout);
         sprintf(buff,"Welcome!\n");
         write(cilent_fd,buff,strlen(buff)+1);  //写会
         bzero(buff,sizeof(buff));
    }
    close(sockfd);
    close(cilent_fd);

    return 0;
}
