#include <iostream>
using namespace std;
struct process
{
    int bru_time;
    char p[4];
    int arr_time;
    int response_time;
    int completion_time;
    int wait_time;
    int tat_time;
};
int temp;
int sq = 0;
int idx = -1;
int last = -1;
int running_queue[100] = {0};
int tot_wait_time;
int tot_response_time;
int tot_completion_time;
int tot_tat_time;
float avg_wait_time;
float avg_tat_time;
float avg_response_time;
float avg_completion_time;

int main()
{
    struct process p[100];
    int brust_remain[100];
    int time;
    int n;
    cout << "Enter your total no. process" << endl;
    cin >> n;
    cout << "Enter your Quantum time" << endl;
    cin >> time;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter your process id" << endl;
        cin >> p[i].p;
        cout << "Enter the arrival time" << endl;
        cin >> p[i].arr_time;
        cout << "Enter your brust time" << endl;
        cin >> p[i].bru_time;
        brust_remain[i] = p[i].bru_time;
        p[i].response_time = -1;
    }
    int complete = 0;
    int is_complete = 0;
    int idx = -1;
    cout << "Gantt__chart" << endl;
    while (1)
    {
        for (int i = 0; i < n; i++)
        {
            temp = time;
            if (brust_remain[i] == 0)
            {
                complete++;
                continue;
            }
            if (brust_remain[i] > time)
            {
                brust_remain[i] -= time;
                idx = i;
            }
            else
            {
                if (brust_remain[i] >= 0)
                {
                    temp = brust_remain[i];
                    brust_remain[i] = 0;
                    idx = i;
                }
            }
            sq = sq + temp;
            p[i].tat_time = sq;
            p[i].wait_time = p[i].tat_time - p[i].bru_time;
            p[i].completion_time = p[i].tat_time + p[i].arr_time;
            if (p[i].response_time = -1)
            {
                p[i].response_time = sq - p[i].arr_time;
            }
            if (last != idx)
            {
                cout << p[i].p << " " << endl;
            }
            else
            {
                cout << "->" << p[i].p << " " << endl;
                // cout<<"->"<<endl;
            }
        }
        if (n == complete)
        {
            break;
        }
    }

    cout << "P"
         << "|"
         << "AT"
         << "|"
         << "TAT"
         << "|"
         << "WT"
         << "|"
         << "RT"
         << "|" << endl;
    for (int i = 0; i < n; i++)
    {
        p[i].wait_time = p[i].tat_time - p[i].bru_time;
        // cout<<p[i].p<<endl;
        // cout<<p[i].arr_time<<endl;
        // cout<<p[i].arr_time<<endl;

        cout << "|" << p[i].p << "|" << p[i].completion_time << "|" << p[i].tat_time << "|" << p[i].wait_time << "|" << p[i].response_time << endl;
        tot_wait_time += p[i].wait_time;
        tot_completion_time += p[i].completion_time;
        tot_tat_time += p[i].tat_time;
    }
    avg_tat_time = tot_tat_time / (float)n;
    avg_completion_time = tot_completion_time / (float)n;
    avg_wait_time = tot_wait_time / (float)n;
    cout << "AVERAGE_TAT_TIME->" << avg_tat_time << endl;
    cout << "AVERAGE_WAIT_TIME->" << avg_wait_time << endl;
    cout << "AVERAGTE_COMPLETION_TIME->" << avg_completion_time << endl;
    return 0;
}