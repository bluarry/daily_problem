#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char buff[1024];
	int fd[2];
	int *writefd=&fd[1];
	int *readfd=&fd[0];
	
	printf("ALLParent: I am the Father process!\n");
	printf("ALLParent: my pid =%d\n",getpid());
	printf("ALLParent: my parent pid=%d\n",getppid());	

	sprintf(buff,"Hello Child process!\n");
	if(pipe(fd)==-1){
		perror("pipe Error");
		exit(1);
	}
	pid_t pid=fork();
	if(pid<0){
		perror("Create process ERROE!");
		exit(1);
	}
	if(pid>0){
		printf("Parent: I am the Father process!\n");
		printf("Parent: my pid =%d\n",getpid());
		printf("Parent: my parent's pid =%d\n",getppid());		
		printf("Parent: i will tell my child: %s\n",buff);
		write(*writefd,buff,sizeof(buff));
		printf("Parent: I will exit!\n");
	}else{
		char tembuff[1024];
		memset(tembuff,0,sizeof(tembuff));
		printf("Child: I am the Child process!\n");
		printf("Child: my pid =%d\n",getpid());
		printf("Child: my parent's pid =%d\n",getppid());		
		read(*readfd,tembuff,sizeof(tembuff));
		printf("Child: I recived message from parent: %s\n",tembuff);
		printf("Child: I will exit!\n");	
	}
	return 0;
}
