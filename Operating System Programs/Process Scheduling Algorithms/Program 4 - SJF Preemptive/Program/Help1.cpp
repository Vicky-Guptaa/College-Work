#include <stdio.h>
#include <limits.h>
#include <string.h>
struct Node
{
    char Process[3];
    int Burst_Time;
    int Completion_Time;
    int Arrival_Time;
    int Turn_Around_Time;
    int Waiting_Time;
    int Response_Time;
} p[11];

struct GanttChart
{
    char Name[3];
    int Start;
    int End;
} Helper[10];

void table(struct Node p[], int n, int ACT_BT[])
{
    printf("Process\t Burst Time\t Arrival Time\t Completion Time\t Waiting Time\t Turn Around Time\t Response Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t %d\t %d\t %d\t %d\t %d\t %d\t", p[i].Process, ACT_BT[i], p[i].Arrival_Time, p[i].Completion_Time,
               p[i].Waiting_Time, p[i].Turn_Around_Time, p[i].Response_Time);
        printf("\n");
    }
    printf("\n \n");
}

void gantt_chart(int j)
{
    for (int i = 0; i < j; i++)
    {
        printf("| %s\t ", Helper[i].Name);
    }
    printf("|");
    printf("\n");
    for (int i = 0; i < j; i++)
    {
        printf(" %d to %d ", Helper[i].Start, Helper[i].End);
    }
}

int main()
{
    int n, count = 0, flag, j = 0;
    int ACT_BT[20];
    int Current_Time = 0;
    int Min_Index;
    float AVG_CT = 0, AVG_WT = 0, AVG_RT = 0, AVG_TAT = 0;
    printf("Enter no. of Process: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("For %dth process\n", i + 1);
        printf("Enter process ID: ");
        scanf("%s", p[i].Process);
        printf("\n");

        printf("Enter Burst Time: ");
        scanf("%d", &p[i].Burst_Time);
        printf("\n");

        printf("Enter Arrival Time: ");
        scanf("%d", &p[i].Arrival_Time);
    }

    for (int i = 0; i < n; i++)
    {
        ACT_BT[i] = p[i].Burst_Time;
    }
    p[10].Burst_Time = INT_MAX;
    while (count != n)
    {
        Min_Index = 10;
        for (int i = 0; i < n; i++)
        {
            if (p[i].Burst_Time <= p[Min_Index].Burst_Time && (p[i].Arrival_Time <= Current_Time && p[i].Burst_Time > 0))
            {
                flag = Min_Index;
                Min_Index = i;
                if (p[i].Burst_Time == p[flag].Burst_Time && p[i].Arrival_Time > p[flag].Arrival_Time)
                {
                    Min_Index = flag;
                }
                if (p[Min_Index].Burst_Time == ACT_BT[Min_Index])
                {
                    p[Min_Index].Response_Time = Current_Time;
                }
            }
        }
        p[Min_Index].Burst_Time = p[Min_Index].Burst_Time - 1;

        if (Min_Index != 10)
        {
            strcpy(Helper[j].Name, p[Min_Index].Process);
            Helper[j].Start = Current_Time;
            Helper[j].End = Current_Time + 1;
            j++;
        }
        Current_Time++;

        if (p[Min_Index].Burst_Time == 0)
        {
            count++;
            p[Min_Index].Completion_Time = Current_Time;
            p[Min_Index].Turn_Around_Time = p[Min_Index].Completion_Time - p[Min_Index].Arrival_Time;
            p[Min_Index].Waiting_Time = p[Min_Index].Turn_Around_Time - ACT_BT[Min_Index];

            AVG_CT = AVG_CT + p[Min_Index].Completion_Time;
            AVG_TAT = AVG_TAT + p[Min_Index].Turn_Around_Time;
            AVG_RT = AVG_RT + p[Min_Index].Response_Time;
            AVG_WT = AVG_WT + p[Min_Index].Waiting_Time;
        }
    }
    table(p, n, ACT_BT);
    printf("\n");
    j--;
    gantt_chart(j);
    printf("\n");
    AVG_CT = AVG_CT / n;
    AVG_TAT = AVG_TAT / n;
    AVG_RT = AVG_RT / n;
    AVG_WT = AVG_WT / n;

    printf("Average Completion_Time = %f\n", AVG_CT);
    printf("Average Turn_Around_Time = %f\n", AVG_TAT);
    printf("Average Waiting_Time = %f\n", AVG_WT);
    printf("Average Response_Time = %f\n", AVG_RT);
    return 0;
}

/*
5
p1
1
2
p2
5
1
p3
1
4
p4
6
0
p5
3
2
*/