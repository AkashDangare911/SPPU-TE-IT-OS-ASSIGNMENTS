#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#define INT_MAX 2147483647

typedef struct Process
{
    int pid;
    int bt;
    int art;
} proc;

void getTat(proc arr[],int tat[],int n)
{
    int rt[n];

    for(int i=0;i<n;i++)
        rt[i] = arr[i].bt;

    int current_time=0, complete=0,
    minm = INT_MAX,smallestRTpro = 0,
    finish_time;

    bool check = false;

    while(complete != n)
    {
        for(int j=0;j<n;j++)
        {
            if( (arr[j].art <= current_time) && (rt[j]<minm) && (rt[j] >0) )
            {
                minm = rt[j];
                smallestRTpro = j;
                check = true;
            }
        }

        if(check == false)
        {
            current_time++;
            continue;
        }

        rt[smallestRTpro]--;

        minm = rt[smallestRTpro];

        if(minm == 0)
            minm = INT_MAX;

        if(rt[smallestRTpro] == 0)
        {
            complete++;
            check = false;

            finish_time = current_time + 1;

            tat[smallestRTpro] = finish_time - arr[smallestRTpro].art;
        }

        current_time++;
    }
}

void getWait(proc arr[],int wt[],int tat[],int n)
{
    for(int i=0;i<n;i++)
        wt[i] = tat[i] - arr[i].bt;

}

void find(proc arr[],int n)
{
    int wt[n],tat[n],total_wt=0,total_tat=0;

    getTat(arr,tat,n);

    getWait(arr,wt,tat,n);

    printf("Process\t\tBurst\t\tWaiting\t\tTurnAround\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t\n",i+1,arr[i].bt,wt[i],tat[i]);
    }

    for(int i=0;i<n;i++)
    {
        total_tat += tat[i];
        total_wt += wt[i];
    }

    printf("Total turn around time is : %f\n",(float)((float)total_tat/n));
    printf("Total waiting time is : %f\n",(float)((float)total_wt/n));

}

int main()
{
    proc arr []= {  { 1, 5, 0 }, 
                    { 2, 3, 1 },
                    { 3, 4, 2 }, 
                    { 4, 1, 4 }};


    int size = sizeof(arr)/sizeof(arr[0]);
    find(arr,size);

    return 0;
}