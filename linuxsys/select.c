#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/select.h>
#include <stdlib.h>

int main()
{
    int sel;
    fd_set rfd;
    struct timeval time;
    time.tv_sec = 10;
    time.tv_usec = 0;

    FD_ZERO(&rfd);
    FD_SET(0, &rfd); /* Watch stdin (fd = 0) to see when it has input. */

    sel = select(1, &rfd, NULL, NULL, &time);

    if (sel)
        printf("\nData available\n");
    else
        printf("\nNo data\n");

    return 0;
}