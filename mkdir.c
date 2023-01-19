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

int main(int noofargs, char *args[])
{   char temp[20] = "";
    int f = 0;
    char cmdname[20] = "";
    strcpy(cmdname,args[1]);       
    char opt[100] = "";
    if(args[1]!=NULL)
    {
    strcpy(opt,args[1]);
    }
    if(noofargs<2)
    {
        printf("ERROR");
    }
    else{
        if(!strcmp(cmdname,"-v"))
        { 
           
           if(mkdir(args[2],0777)!=0)
            {
                printf("Directory can not be created !!");
            }
            else{
                printf("Directory created %s",args[2]);
            }
        }
        else if(!strcmp(cmdname,"-d"))
        {
           for(int i=0;i<strlen(args[1]);i++)   
            { 
             
              if(opt[i]=='/' && f == 0)
              {
                mkdir(temp,0777);
                chdir(temp);
                strcpy(temp,"");
                int f = 1;
              }
              else if(opt[i]=='/' && f == 1)
              {
                mkdir(temp,0777);
                chdir(temp);
                strcpy(temp,"");
                int f = 1;
              }
              
              temp[i]=opt[i];
            }
        }
        else{
            if(!mkdir(args[2],0777))
            {
                printf("Directory can not be created !!");
            }
        }
    }





return 0;
}
    