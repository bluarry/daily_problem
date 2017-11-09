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
    struct sockaddr_in caddr;
    caddr.sin_family=AF_INET;
    caddr.sin_port=htons(32767);
    caddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    //inet_aton("127.0.01",&saddr.sin_addr);

    if(connect(s_c,(struct sockaddr *)&caddr,sizeof(caddr)) < 0)
    {
        printf("连接失败\n" );
        exit(1);
    }
    printf("连接成功\n" );



    char buff[1024];
    bzero(buff,sizeof(buff));
    while(1){
       ssize_t ssize=read(0,buff,1024);
       if(ssize<=0){
           break;
       }
       write(s_c,buff,sizeof(buff)); //发送给服务器
       ssize=read(s_c,buff,1024);
       write(1,buff,ssize);        //写到标准输出
       memset(buff,0,sizeof(buff));
   }
    return 0;
}
