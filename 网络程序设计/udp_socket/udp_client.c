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

int main(int argc, char const *argv[]) {

    int clifd=socket(AF_INET,SOCK_DGRAM,0);
    if(clifd < 0){
        ERREXT("socket 创建失败");
    }

    struct sockaddr_in servaddr;
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(32767);
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");


    char sendbuff[1024]={0};
    char recvbuff[1024]={0};
    while(fgets(sendbuff,1024,stdin)){
        sendto(clifd,sendbuff,sizeof sendbuff,0,(struct sockaddr *)&servaddr,sizeof(servaddr));
        memset(recvbuff,0,sizeof recvbuff);
        int size=recvfrom(clifd,recvbuff,1024,0,NULL,NULL);

        fputs(recvbuff,stdout);
    }

    close(clifd);


    return 0;
}
