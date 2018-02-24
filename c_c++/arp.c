#include "stdio.h"
#include "strings.h"
void main()
{
char *pchCmd= "ping -b 135.46.123.63 -c 20";
char *pchCmd1 = "arp -n | awk '{print $1}'";
char chBuff[1024];
FILE *pfCmd = NULL;

memset(chBuff,0,1024);
// printf("Cmd given to device: (%s)", pchCmd);
pfCmd = popen(pchCmd, "r");
while(fgets(chBuff, sizeof(chBuff), pfCmd))
{
puts(chBuff);

}
pclose(pfCmd);

memset(chBuff,0,1024);
printf("Cmd given to device: (%s)", pchCmd1);
pfCmd = popen(pchCmd1, "r");
while(fgets(chBuff, sizeof(chBuff), pfCmd))
{
puts(chBuff);

}
pclose(pfCmd);
}
