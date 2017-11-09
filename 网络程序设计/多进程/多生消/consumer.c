#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
typedef int sem_t;
union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO   (Linux-specific) */
 };
sem_t Create_sem(key_t key,int value){
    union semun sem;
    sem.val=value;

    sem_t semid=semget(key,1,IPC_CREAT|0666);
    if(semid <0) return semid;
    semctl(semid,0,SETVAL,sem);
    return semid;
}
int Sem_P(sem_t semid)
{
    struct sembuf sops={0,-1,SEM_UNDO};
    return (semop(semid,&sops,1));
}
int Sem_V(sem_t semid)
{
    struct sembuf sops={0,+1,SEM_UNDO};
    return (semop(semid,&sops,1));
}
void del_sem(sem_t semid) {
    union semun sem;
    semctl(semid,0,IPC_RMID,sem);
    semctl(semid,1,IPC_RMID,sem);
}
int main(int argc, char const *argv[])
{
    key_t key1=ftok(".",1);
    sem_t S1=Create_sem(key1,3);
    if(S1<0) { perror("创建信号量失败"); exit(1); }
    key_t key2=ftok(".",2);
    sem_t S2=Create_sem(key2,1);
    if(S2<0) { perror("创建信号量失败"); exit(1); }
    key_t key3=ftok(".",3);
    sem_t mutex=Create_sem(key3,1);
    if(mutex<0) { perror("创建信号量失败"); exit(1); }

    int count=20;

    char ttime[64];
    time_t t;
    while(count--)
    {
        Sem_P(S2);
        Sem_P(mutex);
        t = time(0);
        strftime( ttime, sizeof(ttime), "%Y/%m/%d %X : ",localtime(&t) );
        printf("%s 消费者%s 从缓冲区拿出一件产品 \n",ttime,argv[1] ); sleep(1);
        Sem_V(mutex);
        Sem_V(S1);
        t = time(0);
        strftime( ttime, sizeof(ttime), "%Y/%m/%d %X : ",localtime(&t) );
        printf("%s 消费者%s 消费拿出的产品 \n",ttime,argv[1] ); sleep(1);
    }


    return 0;
}
