#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

// char*argv[] = {"fileName", arr,NULL};

int main(int argc, char *argv[])
{

    printf("\nInside the reverse of the child process \n");

    int size = 4;

    printf("size of array : %d \n", size);

    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d ", (argv[1])[i]);
    }

    printf("\n");

    exit(EXIT_SUCCESS);
}