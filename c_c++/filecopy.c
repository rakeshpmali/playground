#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fdCfgFile = 0, fdTSFile = 0; 
    char *apchTSName = "testsuite";
    char *pchTSFileName = NULL;
    char tmpBuf[4096];
    ssize_t nRead, nWrite;

    fdCfgFile = open("file1.txt", O_RDONLY);
    if (fdCfgFile < 0) 
    {    
        printf("\nFailed to open file1.txt file\n");
        return -1;
    }    

    printf("\nfile1.txt opened\n");

    asprintf(&pchTSFileName,"%s",apchTSName);
    strcat(pchTSFileName,".txt");

    printf("\nFilename Done");

    fdTSFile = open(pchTSFileName, O_WRONLY | O_CREAT, 0666);
    if (fdTSFile < 0) 
    {    
        printf("\nFailed to open/write %s file !", pchTSFileName);
        close(fdCfgFile);
        close(fdTSFile);
        return -1;
    }    

    printf("\nBoth Files Opened");

    while ((nRead = read(fdCfgFile, tmpBuf, sizeof tmpBuf)) > 0) 
    {    
        nWrite = write(fdTSFile, tmpBuf, nRead);
        if (nWrite <= 0) { 
            printf("\nFailed to write into %s file !\n", pchTSFileName);
            close(fdCfgFile);
            close(fdTSFile);
            return -1;
        }
    }
    
    printf("\nCopying Done\n");

    close(fdCfgFile);
    close(fdTSFile);
    return 0;
}
