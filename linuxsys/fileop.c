#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
        int fd,count;
        char buff[6] = "Linux\n",readbuff[6]="";
        fd = open("newfile.txt",O_RDWR | O_CREAT,(mode_t) 0777);

        printf("\nFD = %d\n",fd);
        write(fd,buff,6);

        lseek(fd,0,SEEK_SET);
        count = read(fd,readbuff,6);

        printf("COUNT :: %d\n",count);

        printf("File Contents: ");
        puts(readbuff);
        printf("\n");

        close(fd);
        return 0;
}