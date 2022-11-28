#include <stdio.h>
#include <unistd.h>

void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array after sorting in ascending order: ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
}

void SelectionSortD(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int MI = i;
        for (int j = i + 1; j < n - 1; j++)
        {
            if (arr[j] > arr[MI])
            {
                MI = j;
            }
        }
        int temp = arr[MI];
        arr[MI] = arr[i];
        arr[i] = temp;
    }
    printf("Array after sorting descending order: ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
}

int main()
{
    int n;
    printf("Enter the size of an array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements in array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int F = fork();
    if (F == 0)
    {
        printf("\nChild Process...\n");
        BubbleSort(arr, n);
    }
    else
    {
        printf("\nParent Process....\n");
        SelectionSortD(arr, n);
    }

    return 0;
}
