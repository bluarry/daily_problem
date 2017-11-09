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

    struct sockaddr_in serveraddr;

    /* 创建socket */
    int s=socket(AF_INET,SOCK_STREAM,0);
    if(s < 0){
        printf("创建socket失败\n");
        exit(1);
    }
    printf("socket 创建成功\n");

    bzero(&serveraddr,sizeof(serveraddr));
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(PORT);
    // serveraddr.sin_addr.s_addr=inet_addr(DES);
    // serveraddr.sin_addr.s_addr=htons(INADDR_ANY);
    inet_aton(DES,&serveraddr.sin_addr);

    /* 链接服务器 */
    if(connect(s, (struct sockaddr *)& serveraddr,sizeof(struct sockaddr_in)) == -1)
    {
        printf("服务器链接失败\n" );
        close(s);
        exit(1);
    }
    printf("服务器链接成功\n");

    char buff[1024];
    while(1){
        ssize_t ssize=read(0,buff,1024);
        if(ssize<=0){
            break;
        }
        write(s,buff,sizeof(buff)); //发送给服务器
        ssize=read(s,buff,1024);
        write(1,buff,ssize);        //写到标准输出
        memset(buff,0,sizeof(buff));
    }



    return 0;
}
