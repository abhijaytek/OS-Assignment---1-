#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int noOfarg, char *args[])
{
    int a = 1;
    if (noOfarg < 2){ 
        //PRINTING ERROR 
        printf("ERROR");
    }
    else{
        char cmdname[20] = "";
        strcpy(cmdname,args[1]);
        
        char filename[100] = "";
        strcpy(cmdname,args[2]);
        if(!strcmp(cmdname,"cat"))
        {
            if(!strcmp(args[3],NULL))
            {
                //Function1
            }
            else if(strcmp(args[3],NULL))
            {
                //Function2
            }
            else if{
                int a = 0;
                
            }
        }
        

    }
    
    return 0;
}