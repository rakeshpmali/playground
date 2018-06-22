#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
int main()
{
        int fd;
        char buff[1];
        fd = open("testfile.txt",O_RDONLY,(mode_t)0700);

        while(read(fd,buff,1) > 0)
                write(1,buff,1);

        close(fd);
        return 0;
}
