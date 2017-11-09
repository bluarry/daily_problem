#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <unistd.h>



typedef int sem_t;
char msg[]={"这是一则共享的消息！"};


union semun {
             int              val;    /* Value for SETVAL */
             struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
             unsigned short  *array;  /* Array for GETALL, SETALL */
         };
sem_t Create_Sem(key_t key,int values){
    union semun smu;
    smu.val=values;

    sem_t semid=semget(key,1,IPC_CREAT |0666);
    if(semid <0) {
        printf("创建失败 semid=%d\n",semid);
        return semid;
    }
    semctl(semid,0,SETVAL,smu);
    return semid;
}
int Sem_P(int Semid)
{
    struct sembuf smbff={0,-1,SEM_UNDO};

    return (semop(Semid,&smbff,1));
}
int Sem_V(int Semid)
{
    struct sembuf smbff={0,+1,SEM_UNDO};

    return (semop(Semid,&smbff,1));
}
int Del_Sem(int semid)
{
    union semun s;
    s.val=0;
    return semctl(semid,0,IPC_RMID,s);
}
int main()
{
    key_t key=ftok(".",'a');

    //申请一段共享内存
    int  shmid=shmget(key,1024,IPC_CREAT|0604);

    sem_t S=Create_Sem(key,1);

    pid_t pid=fork();
    if(pid<0){
        perror("fork Error");
        exit(1);
    }else if(pid==0){ //子
        char* shms=(char *)shmat(shmid,0,0);
        memcpy(shms,msg,strlen(msg)+1);
        printf("子进程已将消息写进共享内存\n");

        //断开与共享内存的链接
        shmdt(shms);

        sleep(0.5);
        Sem_P(S);
        printf("信号量S删除，子进程退出\n" );
        Del_Sem(S);
    }else{
        char *shmc=shmat(shmid,0,0);
        Sem_P(S); 
        printf("父进程从共享内存读到消息: %s\n",shmc );
        shmdt(shmc);
        Sem_V(S);
        printf("父进程退出\n");
    }

    return 0;
}
