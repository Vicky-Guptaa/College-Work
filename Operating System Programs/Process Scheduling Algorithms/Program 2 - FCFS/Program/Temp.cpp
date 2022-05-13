#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
//  Write a program to implement the First Come First Serve scheduling algorithm and find the average
// turnaround time, waiting time, completion time and response time for overall process. Also Print Gantt
// chart for it.
int n;
struct process
{
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int finishing_time;
    int turn_around_time;
};
process P[N];

void FCFS()
{
    double total_waiting_time = 0.0;
    double total_turn_around_time = 0.0;
    for (int i = 0; i < n; i++)
    {
        P[i].finishing_time = P[i - 1].finishing_time + P[i].burst_time;
        P[i].turn_around_time = P[i].finishing_time - P[i].arrival_time;
        P[i].waiting_time = P[i].turn_around_time - P[i].burst_time;

        total_waiting_time += P[i].waiting_time;
        total_turn_around_time += P[i].turn_around_time;
    }
    cout << fixed << setprecision(2);
    cout << "Average Waiting Time: " << (total_waiting_time / n) << "\n";
    cout << "Average Turn Around Time: " << (total_turn_around_time / n) << "\n";
    return;
}

void print_table(process P[], int n)
{
    int i;

    puts("+-----+------------+--------------+-----------------+-----------------+-----------------+-----------------+");
    puts("| PID | Burst Time | Waiting Time | Turnaround Time |   Arrival Time  | Completion Time |  Response Time  |");
    puts("+-----+------------+--------------+-----------------+-----------------+-----------------+-----------------+");

    for (i = 0; i < n; i++)
    {
        printf("| %2d  |     %2d     |      %2d      |        %2d       |        %2d       |\n", P[i].id, P[i].burst_time, P[i].waiting_time, P[i].turn_around_time, P[i].arrival_time);
        puts("+-----+------------+--------------+-----------------+-----------------+-----------------+-----------------+");
    }
}

void print_gantt_chart(process P[], int n)
{
    int i, j;

    printf(" ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < P[i].burst_time; j++)
            printf("--");
        printf(" ");
    }
    printf("\n|");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < P[i].burst_time - 1; j++)
            printf(" ");
        printf("P%d", P[i].id);
        for (j = 0; j < P[i].burst_time - 1; j++)
            printf(" ");
        printf("|");
    }
    printf("\n ");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < P[i].burst_time; j++)
            printf("--");
        printf(" ");
    }
    printf("\n");

    printf("0");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < P[i].burst_time; j++)
            printf("  ");
        if (P[i].turn_around_time > 9)
            printf("\b");
        printf("%d", P[i].turn_around_time);
    }
    printf("\n");
}

int main()
{
    cout << "Number of Processes: ";
    cin >> n;

    cout << "Process Ids:\n";
    for (int i = 0; i < n; i++)
        cin >> P[i].id;

    cout << "Process Burst Times:\n";
    for (int i = 0; i < n; i++)
        cin >> P[i].burst_time;

    cout << "Process Arrival Times:\n";
    for (int i = 0; i < n; i++)
        cin >> P[i].arrival_time;

    FCFS();
    print_table(P, n);
    print_gantt_chart(P, n);

    return 0;
}