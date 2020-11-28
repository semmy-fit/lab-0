#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#define _GNU_SOURCE

int main(int argc,char* argv[]) {
int     fd[2], nbytes;

           pid_t   childpid;
           char    string[20] = "Hello, world,bike\n";
           char string1[20]="apple,cat,\n";
           char    readbuffer[80];

           pipe(fd);

           if((childpid = fork()) == -1)
           {
                   perror("fork");
                   exit(1);
           }

           if(childpid == 0)

           {       
                      
                      
                   /* Потомок закрывает вход */
                   close(fd[0]);
                   printf("write string %s",string);

                   /* Посылаем "string" через выход канала */
                   write(fd[1], string, strlen(string));
                   close(fd[1]);
                   exit(0);
           }
           else
           {
                
               
                    
                   /* Родитель закрывает выход */
                
                   close(fd[1]);

                   /* Чтение строки из канала */
                   nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
                     close(fd[1]);
                     printf("toupper: ");
                   printf("\nReceived string: %s", readbuffer);
                   for(int i=0;i<sizeof(readbuffer);i++)
                   {
                           printf("%c",toupper(readbuffer[i]));
                           
                   }
                       printf("\nReceived string: %s", readbuffer);
                  
           }
}
