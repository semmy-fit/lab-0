#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <pwd.h>
#include <sys/types.h>
#include <grp.h>
//~ #define NAME_MAX 256
 
int main(int argc, char **argv)
{

    DIR *dfd;
    struct dirent *dp;
    char filename[NAME_MAX];
 
    if ( argc < 2 )
        strcpy(filename, ".");
    else
        strcpy(filename, argv[1]);
 
    printf("%s\n\n", filename);
    dfd=opendir(filename);
 
    while( (dp=readdir(dfd)) != NULL )
            printf("%s\n", dp->d_name);
     if(filename=="")
     {
       
     }       
    uid_t id = 0;
    struct passwd *pwd;
    pwd = getpwuid(id);
 
  struct stat statbuf;
  struct group *grp;

if ((grp = getgrgid(statbuf.st_gid)) != NULL)
    printf(" %-8.8s", grp->gr_name);
else
    printf(" %-8d", statbuf.st_gid);
    
    closedir(dfd);
    return 0;
}

    typeOf( name ) char *name;
    {  int type; struct stat st;
       if( stat( name, &st ) < 0 ){
               printf( "%s не существует\n", name );
               return 0;
       }
       printf("Файл имеет %d имен\n", st.st_nlink);

       switch(type = (st.st_mode & S_IFMT)){
       case S_IFREG:
            printf( "Обычный файл размером %ld байт\n",
                       st.st_size ); break;
       case S_IFDIR:
               printf( "Каталог\n" );      break;
       case S_IFCHR:   /* байтоориентированное  */
       case S_IFBLK:   /* блочноориентированное */
               printf( "Устройство\n" );   break;
       case S_IFIFO:
               printf( "FIFO-файл\n" );    break;
       default:
               printf( "Другой тип\n" );   break;
       }       return type;
     }
