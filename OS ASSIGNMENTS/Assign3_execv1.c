#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int partition(int a[], int low, int high)

{

    int i = low, j = high;
    int pivotElement = a[low];

    while (i < j)
    {
        while (pivotElement >= a[i])
            i++;
        while (pivotElement < a[j])
            j--;
        
        if (i < j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int tmp = a[low];
    a[low] = a[j];
    a[j] = tmp;

    return j;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int loc = partition(a, low, high);

        quickSort(a, low, loc - 1);
        quickSort(a, loc + 1, high);
    }
}

int main(int argc, char *argv[])
{
    int i, n;

    printf("\nEnter size of an array: ");
    scanf("%d", &n);

    int a[n];

    printf("\nEnter elements into array: ");

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nArray before sorting : ");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);


    quickSort(a, 0, n - 1); // sort the array

    printf("\nArray after sorting : ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    /*-----------------------------------------------------------------------*/

    char arr[n]; //= {'1' , '2'}

    for (i = 0; i < n; i++)
    {
        arr[i] = a[i];
    }

    char *newargv[] = {NULL, arr, NULL}; /* each element represents a command line argument */

    char *env[] = {NULL}; /* leave the environment list null */

    newargv[0] = argv[1]; //  argv1[] is the new filePath name that we are going to pass in terminal

    int PID = fork();

    if (PID == 0)

    { // newFileTOLoad

        execve(argv[1], newargv, env);

        perror("execve"); /* if we get here, execve failed */

        exit(EXIT_FAILURE);
    }
    else
    {
        printf("\nSorted by Parent Process\n");
    }

    return 0;
}
