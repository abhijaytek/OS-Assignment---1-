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

void onlyls(const char* nameofDirectory){     //TO check if only LS is present
    DIR* directory=opendir(nameofDirectory);

    if(directory==NULL){                      //If there is nothing present in the Directory
        printf("THE DIRECTORY IS EMPTY");
        return ;   //End the function
    }
    struct dirent* var;

    var=readdir(directory);

    while(var!=NULL){    //Reading the whole directory
        printf("%s\n",var->d_name);
        var=readdir(directory);  
    }
    closedir(directory);

    return;    //End the function

}
void lsandq(const char* nameofdirectory){    //TO check if only LS is present along with -Q

    DIR* directory=opendir(nameofdirectory);

    if(directory==NULL){
        printf("THE DIRECTORY IS EMPTY");          //If there is nothing present in the Directory
        return ;    //End the function
    }
    struct dirent* var;

    var=readdir(directory);         

    while(var!=NULL)             //Reading the whole directory
    {          
         
        printf("\"%s\"\n",var->d_name);

        var=readdir(directory);  

    }
    closedir(directory);

    return;            //End the function

}
void lsandm(const char* nameofDirectory){       //TO check if only LS is present along with -Q
    DIR* directory=opendir(nameofDirectory);

    if(directory==NULL){
        printf("THE DIRECTORY IS EMPTY");  
         //If there is nothing present in the Directory
        return ;    //End the function
    }
    struct dirent* var;

    var=readdir(directory);

    while(var!=NULL){    //Reading the whole directory

        printf( "%s, ",var->d_name);

        var=readdir(directory); 
  
    }
    closedir(directory);
    return;            //End the function

}

int main(int noOfarg, char *args[])
{
    
    int a = 1;
    if (noOfarg >2){ 
        //PRINTING ERROR 
        printf("ERROR");
    }
    else{
        char cmdname[20];
        strcpy(cmdname,args[0]);       
        char opt[100] = "";
        if(args[1]!=NULL){
        strcpy(opt,args[1]);
        }
        
        
        if(!strcmp(cmdname,"ls"))
        {
            if(!strcmp(opt,""))    //OPTION 1
            {
                onlyls(".");
            }
            else if(!strcmp(opt,"-Q"))  //OPTION 2
            {
                lsandq(".");
            }
             else if(!strcmp(opt,"-m"))  //OPTION 2
            {
                lsandm(".");
            }
            
        }
        else{
            printf("Wrong Command name !!!");
        }
        

    }
    
    return 0;
}