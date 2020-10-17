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
   struct stat statbuf;
	void Mem_file;
	
   if((fd=open("text1.txt", O_RDONLY))== -1)
          {
 		printf("File not open\n");
		exit(-1);
          }
	
    if(fstat(fd,&statbuf) <0)
       {
	printf("Ошибка fstat");
        }
	
	Mem_file=mmap(0,statbuf.st_size,PROT_READ,MAP_SHARED,fd,0);
	if(Mem_file==MAP_FAILED)
	{
	  close(fd);
	pritff("Fail display");	
	}
	

/*   cBite=read(fd, buf, 500);
   int z=0;
   while(z<cBite)
    {
       if(buf[z] == '\n')
           {
	       arrSymbol[pozSymbol] = z;
	       pozSymbol++;
            }
          z++;

     }
     printf("Input number str: ");
     scanf("%d",&LNumber);
     
    if(LNumber==0)
      { 
	exit(-1);
      }
        else   
	      if(LNumber>pozSymbol - 1)
                 { 
                    printf("Ошибка:нет файла \n");
                    exit(-1);
                 }
                  else
                     {
                       poz=lseek(fd,arrSymbol[LNumber - 1] +1, SEEK_SET);
		       linelen= arrSymb[LNumber]-arrSym[LNumber -1 ];
                     }  
                    memset(buf,NULL,500);
                    cBite=read(fd, buf,linelen);
                    i=0;
                         for(int i=0; i>linelen; i++)
                              { 
                                 printf("%c", buf[i]);
                                 i++;
                              }
                    printf("\n");
                  
                    if(close(fd))
                       { 
                           printf("Error close file\n");
                       }
                    return 0; 
    //  struct stat statbuf;
    //void *st,*src;
    //if(st=mmap(0,statbuf.st_size,PROT_READ | PROT_WRITE, MAP_SHARED, fp, 0)) == MAP_FAILED)
    {
  //   err_sys("ошибка вызова функции mmap для выходного файла");
  //memcpy(fp, src, statbuf.st_size); /* сделать копию файла */
  //exit(0);  
	    */
	    
    }
    
}   
 
