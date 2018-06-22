#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
        int i,opt;
        char file1[20],file2[20];

        printf("\n ENTER THE SOURCE FILENAME :: ");
        gets(file1);

        printf("\nENTER THE TARGET FILENAME :: ");
        gets(file2);

        printf("\n ENTER THE LINK TYPE (1=HARD,2=SOFT):: ");
        scanf("%d",&opt);

        switch(opt)
        {
                case 1: i = link(file1,file2);
                        printf("\n HARD LINK : %s --> %s\n",file1,file2);
                        break;
                case 2: i = symlink(file1,file2);
                        printf("\n SOFT LINK : %s --> %s\n",file1,file2);
                        break;
                default:
                        printf("\n INVALID OPTION !!!!\n");
        }

        return(0);
}