#include <stdio.h>
#include <conio.h>

void main()
{
    int i, processes, sum = 0, count = 0, y, quant,
    total_wt = 0, total_tat = 0, at[10], bt[10], temp[10];

    float avg_wt, avg_tat;

    printf(" Total number of process in the system: ");
    scanf("%d", &processes);
    y = processes;

    for (i = 0; i < processes; i++)
    {
        printf("\n Enter the Arrival and Burst time of the Process[%d]\n", i + 1);

        printf(" Arrival time is: \t"); 
        scanf("%d", &at[i]);

        printf(" \nBurst time is: \t"); 
        scanf("%d", &bt[i]);

        temp[i] = bt[i]; 
    }
    

    printf("Enter the Time Quantum for the process: \t");
    scanf("%d", &quant);

    
    printf("\n Process No \t Burst Time \t TAT \t Waiting Time ");
    sum = 0;
    i = 0;

    while( y != 0 )
    {
        if (temp[i] <= quant && temp[i] > 0) 
        {
            sum = sum + temp[i];
            temp[i] = 0;

            count = 1;
        }
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - quant;
            sum = sum + quant;
        }


        if (temp[i] == 0 && count == 1)
        {
            y--; // decrement the process no.

            printf("\nProcess No[%d] \t\t %d\t\t %d\t\t %d", i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);

            total_wt += sum - at[i] - bt[i];

            total_tat += sum - at[i];

            count = 0;
        }


        if (i == processes - 1)
        {
            i = 0;
        }
        else if (at[i + 1] <= sum)
        {
            i++;
        }
        else
        {
            i = 0;
        }

    }
    // represents the average waiting time and Turn Around time

    avg_wt = total_wt * 1.0 / processes;
    avg_tat = total_tat * 1.0 / processes;

    printf("\n Average Turn Around Time: \t%f", avg_wt);
    printf("\n Average Waiting Time: \t%f", avg_tat);

}