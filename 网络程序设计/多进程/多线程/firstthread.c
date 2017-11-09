#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

static int run =1;
static int retvalue;
void *start_routine(void *arg)
{
    int *running=arg;
    printf("子线程创建完毕，传入参数为:%d\n",*running);

    while(*running)
    {
        printf("子线程正在运行\n" );
        usleep(1);
    }
    printf("子线程退出\n" );
    retvalue=8;
    pthread_exit((void*)&retvalue);
}
int main()
{
    pthread_t pt;
    int ret=-1;
    int times=3;
    int i=0;
    int *ret_join=NULL;

    ret=pthread_create(&pt,NULL,(void *)start_routine,&run);
    if(0!=ret)
    {
        printf("线程创建失败\n");
        return 1;
    }
    usleep(1);
    for(i=0;i<3;i++)
    {
        printf("主线程打印\n");
        usleep(1);
    }
    run=0;
    printf("等待子进程退出\n" );
    usleep(10);
    pthread_join(pt,(void*)&ret_join);
    printf("线程返回值为：%d\n",*ret_join);
  return 0;
}
