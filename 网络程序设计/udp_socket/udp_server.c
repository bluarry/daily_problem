#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>

#define ERREXT(m) \
do{ \
    puts(m); \
    exit(1); \
    }while(0)

void run(int sevfd)
{

    char buff[1024]={0};

    struct sockaddr_in client_addr;
    memset(&client_addr,0,sizeof(client_addr));
    socklen_t lenn=sizeof(client_addr);
    while(1){
        memset(buff,0,sizeof buff);
        ssize_t size=recvfrom(sevfd,buff,sizeof(buff),0,
                (struct sockaddr *)&client_addr,&lenn);

        pid_t pid=fork();
        if(pid < 0) ERREXT("创建进程失败");
        if(0==pid)
        {
            fputs(buff,stdout);
            sendto(sevfd,buff,size,0,(struct sockaddr *)&client_addr,lenn);
            close(sevfd);
            sleep(10);
            exit(0);
        }else
        {
            continue;
        }


    }
}

int main() {

    int sevfd=socket(AF_INET,SOCK_DGRAM,0);
    if(sevfd < 0){
        ERREXT("socket 创建失败");
    }
    struct sockaddr_in servaddr;
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(32767);
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    int opt = 1;
// sockfd为需要端口复用的套接字
    setsockopt(sevfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&opt, sizeof(opt));

    if(bind(sevfd,(struct sockaddr *)& servaddr,sizeof(servaddr)) < 0){
            ERREXT("bind 错误");
    }

    run(sevfd);

    close(sevfd);
    return 0;
}
