#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
int main()
{
        int fd, i = 0;
        char buff[1]="\0", lineBuff[50]="\0";
        fd = open("testfile.txt",O_RDONLY,(mode_t)0700);

        while(read(fd,buff,1) > 0)
        {
                if(buff[0] != '\n')
                {
                    lineBuff[i++] = buff[0];
                }
                else
                {
                    write(1,"[Line]: ", 8);
                    write(1,lineBuff,i);
                    write(1,"\n",1);
                    i = 0;
                    memset(&lineBuff, 0, sizeof(lineBuff));
                }
        }

        close(fd);
        return 0;
}
