#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>

int main(){
    int fd1,fd2;
    
    char *myfifo1="file1",str1[100],str2[100];
    char *myfifo2="file2";


    // create fifo pipes (files)
    fd1=mkfifo(myfifo1,0666);
    fd2=mkfifo(myfifo2,0666);


    // input
    printf("\n Enter the string :");
    fgets(str1,100,stdin);


    // write data on first fifo file
    fd1=open(myfifo1,O_WRONLY);
    write(fd1,str1,strlen(str1)+1);
    close(fd1);


    //Read data from second pipe
    fd2=open(myfifo2,O_RDONLY);
    read(fd2,str2,100);


    printf("\nMessage from FIFO2 process : \n%s",str2);
    close(fd2);
    
    
    return 0;
}

