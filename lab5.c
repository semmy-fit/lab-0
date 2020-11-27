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

           {        string=toupper(string);
                    string1=tolower(string1);
                      
                   strncat (string, string1,11);
                      
                   /* Потомок закрывает вход */
                   close(fd[0]);

                   /* Посылаем "string" через выход канала */
                   write(fd[1], string, strlen(string));
                   exit(0);
           }
           else
           {
                
                   toupper(string);
                    
                   /* Родитель закрывает выход */
                
                   close(fd[1]);

                   /* Чтение строки из канала */
                   nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
                   printf("Received string: %s", readbuffer);
           }
}
