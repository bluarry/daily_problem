#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
typedef int sem_t;
union semun{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
}arg;
sem_t Creatsem(key_t key,int value)
{
    union semun sem;
    sem.val=value;
    sem_t semid=semget(key,1,IPC_CREAT|0666);
    if(semid <0) {
        printf("创建失败 semid=%d\n",semid);
        return semid;
    }

    semctl(semid,0,SETVAL,sem);
    return semid;
}
int Sem_P(sem_t sem)
{
    struct sembuf sops={0,-1,SEM_UNDO};
    return (semop(sem,&sops,1));
}
int Sem_V(sem_t sem)
{
    struct sembuf sops={0,+1,SEM_UNDO};
    return (semop(sem,&sops,1));
}
void del_sem(sem_t semid){
    union semun s;
    s.val=0;
    semctl(semid,0,IPC_RMID,s);
}
//解决多进程的经典消费者，生产这模型
int main()
{
    key_t key1=ftok(".",1234);
    sem_t S1=Creatsem(key1,1);
    if(S1<0){ perror("创建信号量失败"); exit(1);}
    key_t key2=ftok(".",123);
    sem_t S2=Creatsem(key2,0);
    if(S2<0) { perror("创建信号量失败"); exit(1);}
    int count=10;
    time_t t = time(0);
    char tmp[64];
    while(count--)
    {
        Sem_P(S2);
        t = time(0);
        strftime( tmp, sizeof(tmp), "%Y/%m/%d %X : ",localtime(&t) );
        printf("%s 消费者拿出了一件产品\n",tmp);    sleep(1);
        Sem_V(S1);
        t = time(0);
        strftime( tmp, sizeof(tmp), "%Y/%m/%d %X : ",localtime(&t) );
        printf("%s 消费者消费了产品\n",tmp);    sleep(1);
        sleep(1);
    }
    del_sem(S1);del_sem(S2);
    return 0;
}
