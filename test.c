#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
int main() { 
	
long int  ttime;
ttime=time(NULL);
printf("\n");
printf ("Время: %s\n",ctime (&ttime) );
printf("\n");

 printf("I am Test.c called by execvp()\n");
printf("\n");	
 
}
