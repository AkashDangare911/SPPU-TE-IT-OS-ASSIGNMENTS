#include<stdio.h>

int allocated[10][10];
int max[10][10];
int need[10][10];

int available[10];

int processes = 0, resources = 0;

void getInput(int arr[10][10])
{
    for(int i=0;i<processes;i++)
    {
        for(int j=0;j<resources;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
}

void display(int matrix[10][10]){
    for(int i=0;i<processes;i++){
        for(int j=0;j<resources;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void find_need()
{
    for(int i=0;i<processes;i++)
    {
        for(int j=0;j<resources;j++)
        {
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }
}

void banker()
{
    int flag = 0,k = 0;
    int path[10],completed[10];

    for(int j=0;j<10;j++){
        completed[j]=0;     // initilize
    }

    for(int i=0;i<processes;i++)
    {
        flag = 0;
        if(completed[i] == 0)
        {
            for (int r = 0; r < resources; r++)
            {
                if(need[i][r] > available[r])
                {
                    flag = 1;
                    break;
                }
            }

            if(flag == 0)
            {
                completed[i] = 1;
                path[k] = i;
                k++;

                for(int r=0;r<resources;r++){
                    available[r] += allocated[i][r];
                }
                i = -1;
            }
        }
    }

    flag = 0;

    for(int p=0;p<processes;p++)
    {
        if(completed[p] == 0)
        printf("The system contains deadlock !");
        // flag = 1;
        break;
    }


    if(flag == 0)
    {
        printf("The path is :");
        for(int z=0;z<processes;z++)
        {
            printf(" %d ->",path[z]);
        }
    }

}

int main()
{
    printf("Enter no. of processes : ");
    scanf("%d",&processes);

    printf("Enter no. of resouces : ");
    scanf("%d",&resources);

    printf("Enter the allocated matrix : \n");
    getInput(allocated);

    printf("Enter of max Need Matrix : \n");
    getInput(max);

    printf("Enter available resouces : ");
    for(int i=0;i<resources;i++)
    {
        scanf("%d",&available[i]);
    }

    find_need();

    printf("Allocated matrix is : \n");
    display(allocated);

    printf("Max need matrix is : \n");
    display(max);



    banker();

    return 0;

}
