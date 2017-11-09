//管道通信
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERREXT(m) do{ puts(m);exit(1); }while(0)

struct MSG{
    int type;
    char name[40];
    char password[10];
}msg;

int main(int argc, char const *argv[]) {

     int fd[2];
     int* writefd=&fd[1];
     int* readfd=&fd[0];
     int result=pipe(fd);
     if(result<0){
        ERREXT("创建管道失败");
     }

     pid_t pid=fork();
     if(pid==-1)
     {
         ERREXT("进程创建失败");
     }

     if(pid==0)
     {
         close(*readfd);
         struct MSG msg={0,"张三","123"};
         result=write(*writefd,&msg,sizeof msg);
         printf("子进程向父进程发送消息完成\n");
         close(*writefd);
         return 0;
     }else
     {
         close(*writefd);
         struct MSG msg;

         result=read(*readfd,&msg,sizeof msg);
         if(result>0)
         {
             printf("接收到子进程传来的消息 : %d %s %s\n",msg.type,msg.name,msg.password);
         }
         close(*readfd);
         return 0;
     }

     return 0;
 }
