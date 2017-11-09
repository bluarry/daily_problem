#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <time.h>
#define MAXP 10
typedef int sem_t;
union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux-specific) */
};
sem_t Create_sem(key_t key,int value)
{
    union semun sem;
    sem.val=value;
    sem_t semid=semget(key,1,IPC_CREAT|0666);
    if(semid>=0)
        semctl(semid,0,SETVAL,sem);
    return semid;
}
int Sem_P(sem_t semid)
{
    struct sembuf seb={0,-1,SEM_UNDO};
    return (semop(semid,&seb,1));
}
int Sem_V(sem_t semid)
{
    struct sembuf seb={0,+1,SEM_UNDO};
    return (semop(semid,&seb,1));
}
void del_Sem(sem_t semid)
{
    union semun sem;
    semctl(semid,0,IPC_RMID,sem);
    semctl(semid,1,IPC_RMID,sem);
}
int main(int argc, char const *argv[]) {

    key_t key1=ftok(".",1);
    sem_t S=Create_sem(key1,1);
    if(S<0) {perror("创建信号量S失败");exit(1);}

    key_t key2=ftok(".",2);
    sem_t Sn=Create_sem(key2,MAXP);
    if(Sn<0) {perror("创建信号量Sn");exit(1);}

    int cnt=20;
    time_t t;
    char ttime[64];

    while(cnt--)
    {
        Sem_P(S);
        Sem_P(Sn);
        Sem_V(S);
        t=time(0);
        strftime( ttime, sizeof(ttime), "%Y/%m/%d %X : ",localtime(&t) );
        FILE *fp=fopen("test.txt","a+");
        printf("%s %s %s 读了文件\n",ttime,argv[0],argv[1]); sleep(1);
        fprintf(fp,"%s %s %s 读了文件\n",ttime,argv[0],argv[1]);
        Sem_V(Sn);
    }


    del_Sem(S);
    del_Sem(Sn);
    return 0;
}
