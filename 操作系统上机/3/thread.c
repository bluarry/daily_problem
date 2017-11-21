#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

static int share_data=0;
static int run =1;
void *child_thread(void *arg)
{
    int *running=arg;

    while(*running)
    {
        ++share_data;
        printf("子线程打印共享data: %d\n",share_data);
        usleep(1);
    }
    printf("子线程退出\n" );
}
int main()
{
    pthread_t pt;

    int *ret_join=NULL;

    int ret=pthread_create(&pt,NULL,(void *)child_thread,&run);
    if(0!=ret)
    {
        printf("线程创建失败\n");
        return 1;
    }

    usleep(1);

    for(int i=0;i<3;i++)
    {
        ++share_data;
        printf("进程打印共享的data: %d\n",share_data);
        usleep(1);
    }
    run=0;

    printf("等待子进程退出\n" );
    //线程结束
    pthread_join(pt,NULL);

  return 0;
}
