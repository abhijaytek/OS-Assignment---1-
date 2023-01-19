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
void pwdP()
{
    char arr[1000];
    char *path = getcwd(arr, sizeof(arr));   //Standard Command to get Actual Path
    printf("The actual path is : ");
    printf("%s\n", path);
}

void pwdL()         
{
    char arr1[PATH_MAX];
    char arr2[1000];    
    char *res = realpath(arr2, arr1);
    char *path = getcwd(arr2, sizeof(arr2));          //Standard Command to get Symbolic
    printf("The Symolic path is : ");
    printf("%s\n", path);
}
void pwd(char t1[],char t2[])
{
    
    
        char cmdname[20] = "";
        strcpy(cmdname,t1);       
        char opt[100] = "";
        if(t2!=NULL)
        {
        strcpy(opt,t2);
        }
        
        
        if(!strcmp(cmdname,"pwd"))
        {
            if(!strcmp(opt,""))    //OPTION 1
            {
                char cwd[1000];
                getcwd(cwd, sizeof(cwd));
                printf("Current working directory is : %s\n", cwd);  //If there is nothing after pwd
            }
            else if(!strcmp(opt,"-L"))  //OPTION 2
            {
                pwdL();
            }
             else if(!strcmp(opt,"-P"))  //OPTION 2
            {
               pwdP();
            
        
            }
        
        else{
            printf("Wrong Command name !!!");
        }
        

    }
    

}


void cd(char *source)
{
    if(strlen(source)==0)
    {
        chdir("/home");    //Changing Directory to home
    }
    
    else if(strcmp(source,"~"))
    {
        chdir("/home");     //Changing Directory to home
    }
    else if(!strcmp(source,".."))
    {
        chdir("..");       //Changing Directory back two times ..
    }
    else{
        if(chdir(source)!=0)
        {
            exit(EXIT_FAILURE);      //Exit
        }
    }
}
void echo(char* source,char* ptr)
{   
    ptr = strtok(source," ");
    if(!strcmp(source,"-e"))
    {
      if(ptr!=NULL)
      {
        printf("%s",ptr);  //Printing the String

      }
      else{
        printf("\n");      //Not printing anything
      }
    }
    else if(!strcmp(source,"-n"))
    {
        if(ptr!=NULL)
        {
            printf("%s\n",ptr);
        }
        else{
            printf("\n");
        }
    }
    else if(source==NULL){
        printf("\n");

    }
    else{

        if(ptr!=NULL)
      {
        printf("%s %s",source,ptr);  //Printing the String

      }
      else{
        printf("%s",source);      //Not printing anything
      }
    }
}
int main()
{  char userinput[200];
   char temp[1000];
  
  while(1)
  {
   printf("Abhijay# ");
   
   gets(userinput);
   strcpy(temp,userinput);
   char *source=strtok(userinput," ");
//    char *ptr[20];
//    char *token = strtok(userinput," ");
//    ptr[0]=token;
   
//    for(int i=1;i<20;i++)
//    {
//     token = strtok(NULL," ");
//     if(token==NULL) break;
//     ptr[i]=token;
//    }

   if(!strcmp(source,"ls"))
   {
    int id = fork();
    if(id==0)
    {
      execl("./ls",temp,NULL);
    }
    else if (id<0)
    {
      printf("CAN NOT FORK !!");
    }
    else 
    {
        wait(NULL);
    }
   }
   if(!strcmp(source,"mkdir"))
   {
    int id = fork();
    if(id==0)
    {
      execl("./mkdir",temp,NULL);
    }
    else if (id<0)
    {
      printf("CAN NOT FORK !!");
    }
    else 
    {
        wait(NULL);
    }
   }
   if(!strcmp(source,"rm"))
   {
    int id = fork();
    if(id==0)
    {
      execl("./rm",temp,NULL);
    }
    else if (id<0)
    {
      printf("CAN NOT FORK !!");
    }
    else 
    {
        wait(NULL);
    }
   }
   if(!strcmp(source,"date"))
   {
    int id = fork();
    if(id==0)
    {
      execl("./date",temp,NULL);
    }
    else if (id<0)
    {
      printf("CAN NOT FORK !!");
    }
    else 
    {
        wait(NULL);
    }
   }
    if(!strcmp(source,"pwd"))
   {
    char temp1[100];
    char temp2[100];
    
    for(int i =0;i<strlen(userinput);i++)
    {
        if(strcmp(&userinput[i]," "))
        {
          temp1[i]=userinput[i];
        }
        else{
            for(int j=i+1,k=0;j<strlen(userinput);j++,k++)
            {
                temp2[k]=userinput[j];
            }
        }

    }
    pwd(temp1,temp2);
   }
   else if(!strcmp(source,"echo"))
   {
    char copyarr[1000] = "";
    strcpy(copyarr,source);
    echo(source,temp);
   }
   else if(!strcmp(source,"cd"))
   {
    cd(source);
   }
   else if(!strcmp(source,"exit"))
   {
    break;
   }
}
   return 0;
}