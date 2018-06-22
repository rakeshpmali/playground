#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    int status, fd;
    printf("\nWe are in the parent process::\n");
    printf("\n PID of parent is::%d\n", (int)getpid());
    status = fork();

    if (status == 0)
    {
        printf("\n We are in the child process::\n");
        printf("\n PID of child is::%d\n", (int)getpid());
        exit(0);
    } 
    else
    {
        printf("\n We are again in the parent process::\n");
        printf("\n PID of Parent is::%d\n", (int)getpid());
        while (1)
            ;
        wait(NULL);
    }

    return 0;
}