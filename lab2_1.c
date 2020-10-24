#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include<sys/mman.h>
#include <unistd.h>
int main(int argc,char const *argv[])
{
   int fd;
   char buf [500];
   int cBite=0;
   int arrSymb [500];
  int pozSymbol = 1;
   int LNumber;
   int poz;
   arrSymbol[0] = -1;
   int linelen;
	//linelen=0;
   struct stat *statbuf;
	void *Mem_file;
	
   if((fd=open("text.txt", O_RDONLY))== -1)
          {
 		printf("File not open\n");
		exit(-1);
          }
	
	//отображение в память
	Mem_file=mmap(0,statbuf.st_size,PROT_READ,MAP_SHARED,fd,0);
	if(Mem_file==MAP_FAILED)
	{
	  close(fd);
	pritff("Fail display");	
	}
	
	
	int *lengths = NULL;
lengths[i] = Memfile;
int *positions = NULL;

for (int k = 0; k < i; k++)
	{
		printf("pos %d, len %d\n", positions[k], lengths[k]);
	}

	do{
		printf("\nВведите номер строки\n");
		scanf("%d", &num);
		if(num > i+1){
			printf("В файле всего %d строк(и), введите номер строки из этого диапазона\n", i+1);
		}else if(num != 0){
			Memfile= lengths[num-1];
			k = 0;
			while(k < Memfile){
				printf("%c", findPtr[positions[num-1] + k]);
				k++;
			}
		}

 
    
}   
 
