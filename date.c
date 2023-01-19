#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include<dirent.h>
#include<limits.h>
#include<time.h>

int main(int noofargs, char *args[])
{   char temp[20] = "";
    int f = 0;
    char cmdname[20] = "";
    strcpy(cmdname,args[0]);       
    char opt[100] = "";
    if(args[1]!=NULL)
    {
    strcpy(opt,args[1]);
    }
    if(noofargs<2)
    {
        printf("ERROR");
    }

    if(!strcmp(cmdname,"date"))
        {   time_t t = time(NULL);
            struct tm *t2;
            t2 = localtime(&t);
            if(!strcmp(opt,"-r"))    //OPTION 1
            {
                
                if (t == -1)
                 {
                    perror("Error is");
                }
                
                printf("%02d %d %02d:%02d:%02d\n",t2->tm_mday, t2->tm_hour, t2->tm_year + 1900, t2->tm_min, t2->tm_sec);
           }
           else if(!strcmp(opt,"+%Y"))
           {
            printf("%02d",t2->tm_year + 1900);
           }
           else if(!strcmp(opt,"+%B"))
           {
            printf("%02d",t2->tm_mon + 2);
           }
        }
        return 0;
 }