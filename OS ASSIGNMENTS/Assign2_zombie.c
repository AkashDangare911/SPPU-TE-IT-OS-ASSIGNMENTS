#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    pid = fork();
    
    if (pid > 0)
    {
        sleep(30);
        printf("parent process id %d", getpid());
        printf("in parent process");
    }
    else if (pid == 0)
    {
        printf("child process id %d", getpid());
        printf("in child process");
    }
    
    return 1;
}