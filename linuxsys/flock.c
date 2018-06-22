#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd, fc;
    struct flock file_lock;

    fd = open("testfile.txt", O_RDWR);
    //file_lock.l_type = F_RDLCK;
    file_lock.l_type = F_WRLCK;
    file_lock.l_whence = SEEK_SET;
    file_lock.l_start = 0;
    file_lock.l_len = 0;
    file_lock.l_pid = getpid();

    if (fcntl(fd, F_SETLKW, &file_lock) == -1)
        printf("\n FILE LOCK FAILED !\n");
    else
        printf("\n FILE LOCKED !\n");
    
    printf("\n CRITICAL CODE EXECUTION ...\n");
    sleep(2);

    file_lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLKW, &file_lock) == -1)
        printf("\n FILE UNLOCK FAILED !\n");
    else
        printf("\n FILE UNLOCKED !\n");

}