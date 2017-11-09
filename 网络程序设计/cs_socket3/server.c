#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#define BACKLOG 10
int max(int a,int b){return a>b?a:b;}
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
    setsockopt(s_c, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));


    //监听 linten

    if(listen(s_c,BACKLOG) < 0)
    {
        printf("linten 失败\n" );
        exit(1);
    }

    //接收 accept
    //利用多路复用来完成多客户端的连接,无需多进程(线程)

    fd_set rset;
    fd_set aset;

    FD_ZERO(&rset);
    FD_ZERO(&aset);

    int clients[FD_SETSIZE];
    struct sockaddr_in sclients[FD_SETSIZE];

    memset(clients,-1,sizeof(clients));

    int maxfd=s_c;

    FD_SET(s_c,&aset);
    int nready;
    int c_fd;

    while(1)
    {
        rset=aset;
        nready=select(maxfd+1,&rset,NULL,NULL,NULL);
        if(nready==0) continue;
        if (nready == -1)
		{
			if(errno == EINTR){
				continue;
			}
			printf("select error\n");
		}

        if(FD_ISSET(s_c,&rset)){
            //连接
            socklen_t s_len=sizeof(caddr);
            c_fd=accept(s_c, (struct sockaddr *)&caddr, &s_len);
            if(c_fd==-1)
            {
                printf("客户端%s:%d 链接失败\n",inet_ntoa(caddr.sin_addr),ntohs(caddr.sin_port) );
            }
            //将连接的客户端fd记录下来
            for(int i=0;i<FD_SETSIZE;i++)
            {
                if(clients[i]<0)
                {
                    printf("客户端%s:%d 连接成功\n",inet_ntoa(caddr.sin_addr),ntohs(caddr.sin_port) );
                    sclients[i]=caddr;
                    clients[i]=c_fd;
                    maxfd=max(i,maxfd);
                    break;
                }
            }
            //fd_set加入所有的fd
            	FD_SET(c_fd, &aset);
                maxfd=max(c_fd,maxfd);

                if(--nready <=0) continue;
        }
        //对于所有的fd，处理每一个的传输请求
        for(int i=0;i<maxfd;i++)
        {
            c_fd=clients[i];
            if(c_fd<0) continue;
            if(FD_ISSET(c_fd,&rset))
            {
                char buff[1024];

                bzero(buff,sizeof(buff));

                int len=read(c_fd,buff,sizeof(buff));

                if(len < 0 )
                {
                    printf("传输错误\n" );
                    break;
                }
                if(len==0)
                {
                    printf("client %s:%d closed\n",inet_ntoa(caddr.sin_addr),ntohs(caddr.sin_port));
					FD_CLR(c_fd, &aset);
					clients[i] = -1;
					break;
                }
                printf("%s:%d : ",inet_ntoa(sclients[i].sin_addr),ntohs(sclients[i].sin_port));
                fputs(buff,stdout);
                bzero(buff,sizeof(buff));

                if(--nready <=0) continue;
            }
        }





    }



    return 0;
}
