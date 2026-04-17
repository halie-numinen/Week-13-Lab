// where did this come from?e 
#include <stdio.h>
#include <stdlib.h>  
#include <fcntl.h>  
#include <sys/types.h>  
#include <unistd.h>  
#include <errno.h> 
#define SIZE 30 
int main(int argc, char *argv[]) {  
   struct flock fileLock;  
   int fd;  
   char myBuffer[SIZE] = "// where did this come from?"; 
   if (argc < 2) {  
      printf ("usage: filename\n");  
      exit (1);  
   }  
   if ((fd = open (argv[1], O_RDWR)) < 0) {  
      perror ("there is");  
      exit (1);  
   } 
   fileLock.l_type = F_WRLCK; // waiting
   fileLock.l_whence = SEEK_SET;  
   fileLock.l_start = 0;  
   fileLock.l_len = 0;  
   if (fcntl (fd, F_SETLKW, &fileLock) < 0) {  
      perror ("Can't acquire lock");  
      exit (1);  
   } 
   printf("Done waiting. Acquired lock.\n");
//    write (fd, myBuffer, SIZE-2); 
//    sleep (10); 
//    fileLock.l_type = F_UNLCK;
   
   close(fd); 
   return 0;  
} 