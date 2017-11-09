#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>


//消息通信
struct msgmbuf {
    long mtype;       /* message type, must be > 0 */
    char mtext[1024];    /* message data */
};
int main(int argc, char const *argv[]) {

    key_t key=ftok(".",'a');
    if(key<0){
        printf("key创建失败\n" );
        exit(1);
    }

    int msgid=msgget(key,IPC_CREAT|0666);
    if(msgid==-1){
        printf("消息建立失败\n" );
    }

    pid_t pid=fork();
    if(pid<0){
      printf("fork Error\n");
    }else if(pid==0){ //子进程
      struct msgmbuf msg_buf;
      msg_buf.mtype=317;
      sprintf(msg_buf.mtext,"这是一则发送的消息");
      int result=msgsnd(msgid,(void *) &msg_buf,sizeof(msg_buf.mtext),IPC_NOWAIT);
      if(result ==-1){
          printf("消息发送失败\n" );
      }else{
        printf("消息发送成功: %s\n",msg_buf.mtext);
      }

      printf("子进程退出\n");
    }else { //父进程
      struct msgmbuf msg_buf;
      sleep(2);
      int result=msgrcv(msgid,(void *)&msg_buf,sizeof(msg_buf.mtext),317,MSG_NOERROR | IPC_NOWAIT);
      if(result==-1)
      {
          printf("消息接受失败\n" );
      }else{
        printf("消息接受成功\n");
        printf("接受到的消息为 %s\n",msg_buf.mtext );
      }
      printf("父进程退出\n");
      exit(0);
    }
    sleep(2.1);
    int result=msgctl(msgid,IPC_RMID,NULL); //删除消息队列
    if(result==-1)
    {
        printf("消息删除失败\n" );
    }else{
      printf("子进程删除消息队列成功\n");
    }

    return 0;
}
