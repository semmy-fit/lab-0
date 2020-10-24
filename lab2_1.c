#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
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
   arrSymb[0] = -1;
   int linelen;
	//linelen=0;

   if((fd=open("text1.txt", O_RDONLY))== -1)
          {
 		printf("File not open\n");
		exit(-1);
          }


	//отображение в память
	buf=mmap(0,statbuf.st_size,PROT_READ,MAP_SHARED,fd,0);
	
	if(Mem_file==MAP_FAILED)
	{
	  close(fd);
	pritff("Fail display");	
	}
	
	// Размер файла
    struct stat statbuf; 
	
    cBite=stat(fd, &statbuf);
    if ( cByte < 0 )
    {
        printf("fstat error"); 
    }
	

   int z=0;
   while(z<cBite)
    {
       if(buf[z] == '\n')
           {
	       arrSymb[pozSymbol] = z;
	       pozSymbol++;
            }
          z++;

     }
     printf("Input number str: ");
     scanf("%d",&LNumber);
     
    if(L_Number==0)
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
                      
		       lineLen= arrSymbol[LNumber-1] +1; i>arrSymbol[LNumber -1 ];
                     }  
                  
                    i=0;
                         for(int i=arrSymb[LNumber -1 ] + 1; i>i>arrSymb[LNumber -1 ] + 1 lineLen; i++)
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
}   
