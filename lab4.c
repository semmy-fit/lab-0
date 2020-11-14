#include <sys/fcntl.h> /*POSIX*/
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

int main(int argc,char* argv[])
  {
     sem_t *s0;
     sem_t *s1;
     int d=0;
     int error=0;
     char l_sem0[]="/000";
     char l_sem1[]="/111";
     s0=sem_open(l_sem0,O_CREAT|O_EXCL,0777,1);
     s1=sem_open(l_sem1,O_CREAT|O_EXCL,0777,0);
     
     if( s0 == -1 || s1 == -1)
     {
         perror("Err");
         return(-1);
     }
     
     pid_t p;
     p=fork();
     int operate;
     int result;
     int a=5;
    
      
     if(p) 
        {
             for(d=0;d<10;d++)
               {
                  sem_wait(s0);
                  operate=d+a;
                  result=operate;
                  FILE *fp = fopen("test23", "wb");
                  fputs("Child process [ppid= getppid()]/s [result=%d] ", fp);
                  fclose(fp);

                  fp = fopen("test.log", "r+b");
                  fseek(fp, 0, SEEK_SET);
                  fputs("", fp);
                  fclose(fp);
                  sem_post(s1);
               }
     } 
      else 
       {
          for(d=0;d<10;d++)
            {
          
               sem_wait(s1);
                 operate=d-a;
                 result=operate;
                 FILE *fp = fopen("test23", "wb");
                 fputs("Parent process [pid= getpid()]/s [result=%d] ", fp);
                 fclose(fp);

                 fp = fopen("test.log", "r+b");
                 fseek(fp, 0, SEEK_SET);
                 fputs("abc", fp);
                 fclose(fp);
                 sem_post(s0);
          }
         
     }
sem_unlink(l_sem0);
sem_unlink(l_sem1);   

 
return(0);
}
