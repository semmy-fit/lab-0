#include <sys/types.h> /*POSIX*/
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <syslog.h>
#include <stdlib.h>
#include <semaphore.h>
#define DEBUG
#define SEM_FAILED ((sem_t *)(-1))
int main(void){
pid_t p;
int fd;
int operate;
int result;
int a;
int b;
printf("Original program, pid=%d\n", getpid());
p=fork(); 
    sem_t *sem_open(const char *name, O_CREAT,);
if(p==0) {
    printf("In child process, pid=%d, ppid=%d\n", getpid(), getppid());
    a=10;
    b=20;
    operate=a+b;
    result=operate;
    printf("%d\n",result);
    operate=b-a;
    result=operate;
     printf("%d\n",result);
    operate=b/a;
    result=operate;
     printf("%d\n",result);
    operate= b%2;
    result=operate;
     printf("%d\n",result);

 
  
} else {
    printf("In parent, pid=%d, fork returned=%d\n", getpid(), p);
       int d=15;
    int c=2;
    operate=d+c;
    result=operate;
     printf("%d\n",result);
    operate=d-c;
    result=operate;
     printf("%d\n",result);
    operate=d/c;
    result=operate;
     printf("%d\n",result);
    operate= d%2;
    result=operate;
     printf("%d\n",result);
}   

                     int i=0;
    openlog("test",LOG_PID,LOG_USER);

#ifdef DEBUG
    syslog(LOG_DEBUG,"try to sending 10 messages");
#endif

    for (i=0;i<10;i++){
       int d=15;
    int c=2;
             operate=d+c;
    result=operate;
        syslog(LOG_INFO,"info message [result = %d] ",result);

        FILE *fp = fopen("test23", "wb");
    fputs("info message [result = %d]", fp);
    fclose(fp);

    fp = fopen("test", "r+b");
    fseek(fp, 0, SEEK_SET);
    fputs("abc", fp);
    fclose(fp);

                      
    };

#ifdef DEBUG
    syslog(LOG_DEBUG,"try log to stderr");
#endif
    closelog();

    openlog("test_stderr",LOG_PERROR | LOG_PID,LOG_USER);
    syslog(LOG_INFO,"this is attempt to use stderr for syslog");
    closelog();
 int sem_close(sem_t *sem);

}
