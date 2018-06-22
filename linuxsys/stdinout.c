#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
int main()
{
        char buff[100]="\0";

        while(1)
        {
                read(STDIN_FILENO,buff,sizeof(buff));

                write(STDOUT_FILENO,buff,sizeof(buff));

                if(!strcmp(buff,"\n"))
                        break;
        }

        return(0);

}
