
 #include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <pwd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <grp.h>
//~ #define NAME_MAX 256
 
int main(int argc, char **argv)
{

    DIR *dfd;
    struct dirent *dp;
    char filename[NAME_MAX];
 
    if ( argc < 2 ) {strcpy(filename, ".");}
    else
       { strcpy(filename, argv[1]);}
 
    printf("%s\n\n", filename);
    dfd=opendir(filename);
 
    while( (dp=readdir(dfd)) != NULL )
          
          {  printf("%s\n", dp->d_name);}
     if(filename=="")
     {
       
     }       
    uid_t id = 0;
    struct passwd *pwd;
    pwd = getpwuid(id);
 
  struct stat statbuf;
  struct group *grp;

if ((grp = getgrgid(statbuf.st_gid)) != NULL)
  {   printf(" %-8.8s", grp->gr_name);}
else
 {   printf(" %-8d", statbuf.st_gid);
    
    closedir(dfd);
}
    
     char *name;
     
       int type; 
       struct stat st;
       if( stat(name, &st ) < 0 ){
               printf( "%s не существует\n", name );
               return 0;
       }
       printf("Файл имеет %d имен\n",st.st_nlink);
       struct tm *timeinfo=localtime(st.st_mtime);
       int ttime;

       // Считываем текущее время
        ttime = ctime (NULL);

        // С помощью функции ctime преобразуем считанное время в
        // локальное, а затем в строку и выводим в консоль.
        printf ("Время: %s\n",&time);
         
       //type=(st.st_mode & S_IFMT);
  
       if(st.st_mode & S_IFREG)  { printf( "Обычный файл размером %ld байт\n", st.st_size );}                
       if( st.st_mode & S_IFDIR)  { printf( "Каталог\n",st.st_size );}   
       if(st.st_mode & S_IFCHR) { printf("",st.st_size ); }
       if(st.st_mode & S_IFBLK)  { printf( "Устройство\n",st.st_size); } 
       if (st.st_mode  & S_IFIFO { printf( "FIFO-файл\n",st.st_size ); }
               
           if (st.st_mode & S_IROTH)
                {  
                   strcat(Other,"r");
                }
                 else 
                    { strcat(Other,"Обычный файл"); }   
      
           if(st.st_mode &   S_IWOTH  )                
               {
                 strcat(Other,"w");
               }
               else 
                  { strcat(Other,"Обычный файл"); }
           
          if(st.st_mode & S_IXOTH)
              {
                strcat(Other,"x"); 
              } 
               else
                 { 
                 strcat(Other,"Обычный файл"); 
                 }   
    
    
    
    return 0;
}

     
