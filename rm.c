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
    if(args[2]!=NULL)
    {
    strcpy(opt,args[2]);
    }
    
        if(!strcmp(cmdname,"-v"))
        { 
           
           if(remove(args[2])!=0)
            {
                printf("File can not be removed !!");
            }
            else{
                printf("File removed %s",args[2]);
            }
        }
        
       else if(!strcmp(cmdname,"-i"))
       {
		printf("Delete file? (y/n)?\n");   //Asking the user
		char option;
		scanf("%c",&option);
		if(option=='y')
		{			 
           if(remove(args[2])!=0)
            {
                printf("File can not be removed !!");
            }
		}
		else
        {
			int m = 0;
	    }
       } 
       else
       {
       
            if(remove(args[2])!=0)
            {
                printf("File can not be removed !!");
            }

       
    }

return 0;
}
    