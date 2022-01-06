#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>

int main()
     {
        unsigned int status;

        if ( fork() == 0 )  {       /*  == 0 means in child  */
           printf("Child process \n");
           //exit(status);
        }
        else  {                      /* != 0 means in parent */
           //wait(&status);
           printf("parent process \n");
        }
     }
