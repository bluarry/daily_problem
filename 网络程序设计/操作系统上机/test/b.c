#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
typedef int sem_t;




sem_t Creatsem(key_t key,int values)
{
	sem_t sem=semget(key,1,IPC_CREAT|0666);
	

	semctl(sem,IPC_SET,1);
	
	return sem;
}
int Sem_P(sem_t semid)
{
	struct sembuff bu={semid,-1,SEM_UNDO};
	
	return  semop(semid,bu);
}

int Sem_V(sem_t semid)
{
	struct sembuff bu={semid,+1,SEM_UNDO};
	
	return  semop(semid,bu);
}

int main()
{
	key_t key=ftok(".",'a');
	sem_t S1=Creatsem(key,1);
	key_t key2=ftok(".",'b');
	sem_t S2=Creatsem(key2,1);
	
	
	
	return 0;
}
