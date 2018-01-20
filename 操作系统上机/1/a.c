#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
	char buff[1024];
	char buff1[1024];
	int fd[2],fd1[2];
	int *writefd=&fd[1];
	int *readfd=&fd[0];
	int *wfd=&fd1[1];
	int *rfd=&fd1[0]	;



	if(pipe(fd)==-1 || pipe(fd1)==-1){
		perror("pipe Error");
		exit(1);
	}
	pid_t pid=fork();
	if(pid<0){
		perror("Create process ERROE!");
		exit(1);
	}
	if(pid>0){
		sprintf(buff,"Hello Child process!\n");
		printf("Parent: I am the Father process!\n");
		printf("Parent: my pid =%d\n",getpid());
		printf("Parent: my parent's pid =%d\n",getppid());		
		printf("Parent: i will tell my child: %s\n",buff);
		write(*writefd,buff,sizeof(buff));
		read(*rfd,buff1,1024);
		printf("Parent:i recive from my chile: %s \n",buff1);
		printf("Parent: I will exit!\n");
		while(wait(NULL) < -1 ){}
	}else{
		sprintf(buff1,"Hello Parent process\n");	
		memset(buff,0,sizeof(buff));
		printf("Child: I am the Child process!\n");
		printf("Child: my pid =%d\n",getpid());
		printf("Child: my parent's pid =%d\n",getppid());		
		read(*readfd,buff,sizeof(buff));
		printf("Child: I recived message from parent: %s\n",buff);
		printf("Child: I will tell my parent: %s\n",buff1);
		write(*wfd,buff1,1024);
		printf("Child: I will exit!\n");	
	}
	return 0;
}