#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>


int main()
{
        int status;
        status = fork();
        if(status == 0)
        {
          printf("\n We are in the child process::\n");
          printf("\n PID of child is::%d\n",(int)getpid());
        }
        else
        {
          wait(NULL);
          printf("\n We are in the parent process::\n");
          printf("\n PID of Parent is::%d\n",(int)getpid());
        }
return 0;
}
