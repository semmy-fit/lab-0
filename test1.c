#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include <sys/wait.h>
#include <time.h>
int main(int argc,char const *argv[])
{
if(args<2)
   {
       printf ("You forgot to argument 2\n");
   } 
    else 
      {   
          int child_status;
          pid_t p;  /*создание родительского процесса*/
          printf("Parent process, pid=%d\n", getpid());
          p=fork(); /*порождаем новый процесс(дочерний)*/
   
   if(p==0) 
     {
        printf("Child process, ppid=%d, pid=%d\n",getppid(), getpid());
        execvp(argv[1],&argv[1]);} /*замена исоплняемого кода для дочернего процесса*/
        wait(&child_status); /*ожидание заврешения дочернего процесса*/
        exit(1)

    if (WIFEXITED(child_status))
         {
            printf("The child process exited , with exit code %d ", WEXITSTATUS(child_status)); /*вывод кода заврешения дочернего процесса*/
            printf("\n"); 
          }
     }
  /* else 

if(p==0) {
    printf("Child process, pid=%d, ppid=%d\n",getpid(), getppid());
   
        char *args[]={"./test",NULL};
        execvp(args[0],args);  
       
 }

  wait(&child_status); 

 if (WIFEXITED(child_status)) {

 printf("The child process exited normally, with exit code %d ", WEXITSTATUS(child_status));
 }
   printf("\n");
   printf("Parent process exited normally, with exit code  %d", WEXITSTATUS(p)); 
}*/
}

