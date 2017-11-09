#include <stdio.h>
#include <pthread.h>
#include <sched.h>
#include <unistd.h>
void *producer(void* arg);
void *consumer(void* arg);
pthread_mutex_t mutex;
int running =1;
int buff=0;

int main()
{
    pthread_t pro,consu;
    pthread_mutex_init(&mutex,NULL);


    if(pthread_create(&pro,NULL,(void*)producer,NULL) <0)
    {
        printf("线程创建失败\n" );
    }
    if(pthread_create(&consu,NULL,(void*)consumer,NULL) <0)
    {
        printf("线程创建失败\n");
    }
    usleep(10000);
    running=0;
    pthread_join(pro,NULL);
    pthread_join(consu,NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}
void *producer(void* arg){
    while(running)
    {
        pthread_mutex_lock(&mutex);
        buff++;
        printf("生产者生产的总数为 : %d\n",buff);
        pthread_mutex_unlock(&mutex);
        usleep(1);
    }
}
void *consumer(void* arg){
    while(running)
    {
        pthread_mutex_lock(&mutex);
        buff--;
        printf("消费者消费后的总数为 : %d\n",buff);
        pthread_mutex_unlock(&mutex);
        usleep(10);
    }
}
