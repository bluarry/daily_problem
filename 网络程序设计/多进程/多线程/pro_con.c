#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>



void *producer(void* arg);
void *consumer(void *arg);

sem_t S1,S2;
int running =1;
int buff=0;
int main()
{
    pthread_t pro,con;
    sem_init(&S1,0,1);
    sem_init(&S2,0,0);
    pthread_create(&pro,NULL,(void*)producer,NULL);
    pthread_create(&con,NULL,(void*)consumer,NULL);

    sleep(10);
    running =0;
    pthread_join(con,NULL);
    printf("消费者停止\n" );
    pthread_join(pro,NULL);
    printf("生产者停止\n" );
    sem_destroy(&S1);
    sem_destroy(&S2);
    return 0;
}
void *producer(void* arg){
    int semval=0;
    while(running){
        usleep(1);
        sem_wait(&S1);
        printf("生产完总量为：%d\n",++buff );
        sleep(1);
        sem_post(&S2);
    }
}
void *consumer(void *arg){
    int semval=0;
    while(running){
        usleep(1);
        sem_wait(&S2);
        printf("消费完总量为：%d\n",--buff );
        sleep(1);
        sem_post(&S1);
    }

}
