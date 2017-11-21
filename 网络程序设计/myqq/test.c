#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    printf("p %d %d %d\n",getppid(),getpid());
    pid_t pid=fork();
    if(pid==0){
        printf("%d %d\n",getppid(),getpid());
        sleep(2);
        printf("%d %d\n",getppid(),getpid());
        exit(0);
    }
    sleep(1);
    printf("%d %d %d\n",getppid(),getpid(),pid);
    return 0;
}
