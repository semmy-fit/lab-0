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
   arrSymbol[0] = -1;

   if((fd=open("text1.txt", O_RDONLY))== -1)
          {
 		printf("File not open\n");
		exit(-1);
          }

   cBite=read(fd, buf, 500);
   int z=0;
   while(z<cBite)
    {
       if(buf[z] == '\n')
         
            {
               arrSymbol[pozSymbol++] = z;
            }
          z++;

    }
     printf("Input number str: ");
     scanf("%d",$LNumber);
     

    if(L_Number==0)
      { exit(-1);}
        else if(LNumber>pozSymbol - 1)
                 { 
                    printf("Ошибка:нет файла \n");
                    exit(-1);
                 }
              else
               {
                
                   poz=lseek(fd,arrSymbol[LNumber - 1] +1, SEEK_SET);
               }  
                 memset(buf,Null,1000);
                 cBite=read(fd, buf,1000);
                 i=0;
                  while(buf[i] != '\n')
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
 
                
