#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <unistd.h>

typedef int sem_t;
union semun {
			 int              val;
			 struct semid_ds *buf;
			 unsigned short  *array;
		 };


sem_t Creatsem(key_t key,int values)
{
	union semun se;
	se.val=values;
	sem_t semid=semget(key,1,IPC_CREAT|0666);
	semctl(semid,0,SETVAL,se);
	return semid;
}

int Sem_P(sem_t semid)
{
	struct sembuf bu={0,-1,SEM_UNDO};
	return  semop(semid,&bu,1);
}

int Sem_V(sem_t semid)
{
	struct sembuf bu={0,+1,SEM_UNDO};
	return  semop(semid,&bu,1);
}

void del_sem(sem_t semid){
    union semun s;
    s.val=0;
    semctl(semid,0,IPC_RMID,s);
}
int main()
{
	key_t key=ftok(".",'a');
	sem_t S1=Creatsem(key,0);
	key_t key2=ftok("/",'b');
	sem_t S2=Creatsem(key2,0);

	pid_t pid=fork();
	if(pid==0){
		int co=5;
		while (co--) {
			sleep(1);
			printf("正常行车\n");
			sleep(1);
			printf("到站停车\n");
			sleep(1);
			Sem_V(S2);
			Sem_P(S1);
			printf("离站开车\n");
			sleep(1);
		}
	}else
	{
		int co=5;
		while(co--){
			sleep(1);
			printf("售票\n");
			sleep(1);
			Sem_P(S2);
			printf("开车门\n" );
			sleep(1);
			printf("关车门\n" );
			sleep(1);
			Sem_V(S1);
		}
	}
	del_sem(S1);
	del_sem(S2);
	return 0;
}
