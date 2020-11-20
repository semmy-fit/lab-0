#include <stdio.h>
#include <semaphore.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <errno.h>
#define SEM_NAME "/mysem"
#define SEM_NAM1 "/mysem1"

int main(){
  
  sem_t *sem_n;
  sem_t *sem1_n;  
  int ret,val;
  if ((sem_n = sem_open(SEM_NAME, O_CREAT, 0600, 1)) ==SEM_FAILED){
     perror("sem_open");
      return -1;
      }
  if ((sem1_n = sem_open(SEM_NAM1, O_CREAT, 0600,1)) == SEM_FAILED){
      perror("sem_open");
      return -1;
  }
  
pid_t p;
p=fork();

  sem_getvalue(sem_n, &val);
  sem_getvalue(sem1_n, &val);
  if(p==0)
    {   
      int d=5; int a=8;
      int operate=d+a;
      int result=operate;
      printf("Res=%d",result);
              
      FILE *fp;
      char *filename="data1.txt";
      sem_wait(sem_n);
        if((fp= fopen(filename, "w"))==NULL)
              { 
                 perror("Error occured while opening file");
                 return 1;
              }

      fprintf(fp,"Child process ppid=%d\n",getppid());
      fprintf(fp,"result=%d",result);
      fclose(fp);
      sem_post(sem1_n);
      printf("semaphore value = %d\n", val);
   }
     else 
      {
         int t=57;
         int ta=85;
         int operate=t+ta;
         int result=operate;
         printf("Res=%d",result);
         FILE *ft;
         sem_wait(sem1_n);
         char *filename="data1.txt";
       
         if((ft= fopen(filename, "w"))==NULL)
                 {
                 perror("Error occured while opening file");
                 return 1;
                 }

         fprintf(ft,"Parent process pid=%d\n",getpid());
         fprintf(ft,"result=%d",result);
         fclose(ft);
         sem_post(sem_n);

      }

  if ((ret = sem_trywait(sem_n)) != 0 ||(ret = sem_trywait(sem1_n)) != 0  && errno == EAGAIN)

      {  

        sem_wait(sem_n);
        sem_wait(sem1_n);
      }
  
       else if (ret != 0)
         {
           perror("sem_trywait");
           return -1;
         }

 if (sem_post(sem_n) != 0 || sem_post(sem1_n) !=0)   perror("post error");

 sem_close(sem_n);
 sem_close(sem1_n);

 sem_unlink(SEM_NAME);
 sem_unlink(SEM_NAM1);
 return 0;

}
