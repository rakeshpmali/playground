#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
    int i, ppid, cpid;
    ppid = getpid();

    printf("\n We are in the parent process::\n");
    printf("\n PID of parent is::%d\n", (int)getpid());

    if (!fork())
    {
        printf("\n We are in the child process::\n");
        printf("\n PID of child is::%d\n", (int)getpid());
        while (1);
    }
    else
    {
        sleep(5);
        printf("\n We are EXITING the parent process::\n");
        printf("\n PID of Parent is::%d\n", (int)getpid());
        exit(0);
    }
    return 0;
}