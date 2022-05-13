#include <iostream>
using namespace std;

void findWaitingTime(char process[], int n, int bt[], int wt[], int quantum)
{
    int rem_bt[n];
    for (int i = 0; i < n; i++)
    {
        rem_bt[i] = bt[i];
    }
    int t = 0; // Current time
    while (1)
    {
        bool done = true;
        for (int i = 0; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = false;
                if (rem_bt[i] > quantum)
                {
                    t += quantum;
                    rem_bt[i] -= quantum;
                }
                else
                {
                    t = t + rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == true)
            break;
    }
}

void findTurnAroundTime(char process[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
    }
}

void findAverageTime(char process[], int n, int bt[], int at[], int quantum)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(process, n, bt, wt, quantum);
    findTurnAroundTime(process, n, bt, wt, tat);
    printf("Process \t Arival Time \t Burst Time \t Waiting Time \t TurnAroundTime\n");
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << i + 1 << "\t\t" << at[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }
    cout << "Average Waiting Time = " << (float)total_wt / (float)n << endl;
    cout << "Average Turn Around Time = " << (float)total_wt / (float)n;
}

int main()
{
    char process[10];
    int n, bt[100], at[100];
    cout << "Enter no of process: ";
    cin >> n;
    cout << "Enter processes" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> process;
    }
    cout << "Enter burst time" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> bt[i];
    }
    cout << "Enter arrival time" << endl;
    for (int i = 0; i < n; i++)
    {
        // printf("enter the AT of %dth process\n", i + 1);
        cin >> at[i];
    }
    int quantum = 2;
    findAverageTime(process, n, bt, at, quantum);
}