#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#define BACKLOG 10
int main(){

    //创建套接字
    int  s_c=socket(AF_INET,SOCK_STREAM,0);
    if(s_c<0){
        printf("socket 创建失败\n" );
        exit(1);
    }

    //绑定地址 bind
    struct sockaddr_in saddr,caddr;
    saddr.sin_family=AF_INET;
    saddr.sin_port=htons(32767);
    saddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    //inet_aton("127.0.01",&saddr.sin_addr);
    if(bind(s_c,(struct sockaddr *)&saddr,sizeof(saddr)) < 0){
        printf("bind 失败\n" );
        exit(1);
    }

    int opt = 1;
    // 端口复用
    setsockopt(s_c, SOL_SOCKET, SO_REUSEADDR, (const void *)&opt, sizeof(opt));


    //监听 linten

    if(listen(s_c,BACKLOG) < 0)
    {
        printf("linten 失败\n" );
        exit(1);
    }

    //接收 accept


    while(1)
    {
        socklen_t s_len=sizeof(caddr);
        int c_fd=accept(s_c, (struct sockaddr *)&caddr, &s_len);
        if(c_fd==-1)
        {
            printf("客户端%s:%d 断开链接 或 链接失败\n",inet_ntoa(caddr.sin_addr),ntohs(caddr.sin_port) );
            exit(1);
        }
        printf("accept 成功, from %s:%d\n",inet_ntoa(caddr.sin_addr),ntohs(caddr.sin_port));

        pid_t pid=fork();
        if(pid < 0){
            printf("进程创建失败\n" );
            exit(1);
        }
        if(pid==0) //子进程处理链接
        {
            close(s_c);
            char buff[1024];

            while(1)
            {
                ssize_t llen=read(c_fd,buff,sizeof(buff));
                if(llen<=0) break;
                printf("%s : %d : ", inet_ntoa(caddr.sin_addr),ntohs(caddr.sin_port));
                fputs(buff,stdout);
                bzero(buff,sizeof(buff));
                sprintf(buff,"Welcome Client %s:%d\n",inet_ntoa(caddr.sin_addr),ntohs(caddr.sin_port));
                write(c_fd,buff,sizeof(buff));

                bzero(buff,sizeof(buff));
            }

        }
        else{   //父进程继续负责链接
            close(c_fd);

        }



    }








    return 0;
}
