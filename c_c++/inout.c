#include <stdio.h>

int main(void)
{
    int i = 0, j = 0;
    printf("\t%d\n", printf("ThisIsATest"));
    printf("%d\n", scanf("%d %d", &i, &j));

    static char str1[128];
    fflush(stdin);
    fflush(stdout);
    printf("Enter a string: ");
    scanf("%[A-Z]s", str1);  // Capture Capital Characters which are contigous from the first occurrence
    fflush(stdin);
    fflush(stdout);
    printf("You entered: %s\n", str1);
    
    static char str2[128];
    fflush(stdin);
    fflush(stdout);
    printf("Enter a string: ");
    scanf("%[^M]s", str2);  // Capture till you get first occurence of "M", ignore "M" in the scan result
    fflush(stdin);
    fflush(stdout);
    printf("You entered: %s\n", str2);

    printf("PRINTF TEST\n");
    fflush(stdin);
    fflush(stdout);
    puts("PUTS TEST");
    fflush(stdin);
    fflush(stdout);
    fputs("FPUTS TEST\n", stdout);
    
    fflush(stdin);
    fflush(stdout);

    printf("PRINTF%sTEST%s\n");
    fflush(stdin);
    fflush(stdout);
    puts("PUTS%sTEST%s");
    fflush(stdin);
    fflush(stdout);
    fputs("FPUTS%sTEST%s\n", stdout); 
    fflush(stdin);
    fflush(stdout);
    printf("Percent PRINTF%%sTEST\n");
    fflush(stdin);
    fflush(stdout);
    
    printf("PRINTF123%nTEST456789%n\n", &i, &j);
    printf("i = %d\t j = %d\n", i, j);

    printf(5 + "GeeksQuiz\n");      // Quiz --> move 5 places
    printf("%c\n", 5["GeeksQuiz"]); // Q --> *(5 + "GeeksQuiz")
    printf("%c\n", "GeeksQuiz"[5]); // Q --> *("GeeksQuiz" + 5)
    
    fflush(stdin);
    fflush(stdout);

/* Never use gets. It offers no protections against a buffer overflow vulnerability (that is, you cannot tell it how big the buffer you pass to it is, so it cannot prevent a user from entering a line larger than the buffer and clobbering memory).
*/
    char str11[5];
    gets(str11);
    printf("%s\n", str11);
    
    fflush(stdin);
    fflush(stdout);

    char str12[5];
    fgets(str12, 5, stdin);
    printf("%s\n", str12);

    char *s = "Geeks Quiz";
    int n = 7;
    printf("%.*s\n", n, s);

    return 0;
}
