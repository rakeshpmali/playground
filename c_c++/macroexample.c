#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX 100
#define INCREMENT(x) ++x
#define MULTIPLY(a,b) a*b
#define MERGE(a,b) a##b
#define GETSTRING(a) #a
#define PRINT(i,limit) while (i < limit) \
                        { \
                            printf("MacroTest\n"); \
                            i++; \
                        }
#define macro(n,f,u) f##u##n
#define FUN macro(n,f,u)
#define PRINTSTRING(x) (#x)

#define INFO    1
#define ERR     2
#define STD_OUT stdout
#define STD_ERR stderr
#define LOG_MESSAGE(prio, stream, msg, ...) do {\
                        char *str;\
                        if (prio == INFO)\
                            str = "INFO";\
                        else if (prio == ERR)\
                            str = "ERR";\
                        fprintf(stream, "[%s] : %s : %d : "msg" \n", str, __FILE__, __LINE__, ##__VA_ARGS__);\
                    } while (0)


void fun()
{
    printf("C is fun !\n");
}

int main()
{
    int x = 10;
    int i = 0, l = 5;
    char *ptr = "MACRO-TEST";
    printf("MAX = %d\n", MAX);
    printf("x = %d\n", x);
    printf("INCREMENT(x) = %d\n", INCREMENT(x));
    printf("ptr = %s\n", ptr);
    printf("INCREMENT(ptr) = %s\n", INCREMENT(ptr));
    printf("MULTIPLY(2+3,2+3) = %d\n", MULTIPLY(2+3,2+3));
    printf("MERGE(23,32) = %d\n", MERGE(23,32));
    printf("GETSTRING(TEST) = %s\n", GETSTRING(TEST));
    PRINT(i,l);
    printf("Current File :%s\n", __FILE__ );
    printf("Current Date :%s\n", __DATE__ );
    printf("Current Time :%s\n", __TIME__ );
    printf("Line Number :%d\n", __LINE__ );
    FUN();
    
    printf("%s\n", PRINTSTRING(thisisatest)); // IMP 
    printf("%s\n", PRINTSTRING(123456789)); // IMP 

    char *s = "Hello";

    /* display normal message */
    LOG_MESSAGE(ERR, STD_ERR, "Failed to open file");

    /* provide string as argument */
    LOG_MESSAGE(INFO, STD_OUT, "%s Geeks for Geeks", s);

    /* provide integer as arguments */
    LOG_MESSAGE(INFO, STD_OUT, "%d + %d = %d", 10, 20, (10 + 20));

    return 0;
}
