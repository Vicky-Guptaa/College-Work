#include <iostream>
#include <algorithm>
using namespace std;

struct Process
{
    string P_Name;
    int AT;
    int BT;
    int WT;
    int CT;
    int RT;
    int TAT;
};

bool mycomp(Process P1, Process P2)
{

    if (P1.AT != P2.AT)
    {
        return P1.AT < P2.AT;
    }
    else if (P1.BT != P2.BT)
    {
        return P1.BT > P2.BT;
    }
    else
    {
        int num1 = stoi(P1.P_Name.substr(1));
        int num2 = stoi(P2.P_Name.substr(1));
        return num1 < num2;
    }
}

void Print_Bars()
{
    for (int i = 0; i < 100; i++)
        cout << "_";
    cout << "\n";
}

void Average_Time(Process P_Array[], int T_Process)
{
    double Av_CT = 0, Av_RT = 0, Av_WT = 0, Av_TAT = 0;
    for (int i = 0; i < T_Process; i++)
    {
        Av_CT += P_Array[i].CT;
        Av_RT += P_Array[i].RT;
        Av_TAT += P_Array[i].TAT;
        Av_WT += P_Array[i].WT;
    }
    Av_WT /= T_Process;
    Av_TAT /= T_Process;
    Av_RT /= T_Process;
    Av_CT /= T_Process;
    cout << "Average Time For The Different Time In Process Scheduling\n\n";

    cout << "Average Completion Time -> " << Av_CT << "\n";
    cout << "Average Waiting Time -> " << Av_WT << "\n";
    cout << "Average Turn Around Time -> " << Av_TAT << "\n";
    cout << "Average Respond Time -> " << Av_RT << "\n";
}

void GanttChart(Process P_Array[], int T_Process)
{

    cout << "Gantt Chart For Process Scheduling\n";
    cout << "\n";
    if (P_Array[0].AT != 0)
    {
        cout << "|\t\t|  ";
    }
    else
    {
        cout << "|\t";
    }

    for (int i = 0; i < T_Process; i++)
    {
        if (i != 0 && P_Array[i - 1].CT < P_Array[i].AT)
        {
            cout << "\t|\t";
        }
        cout << P_Array[i].P_Name << "\t|\t";
    }
    cout << "\n";

    if (P_Array[0].AT != 0)
    {
        cout << " 0\t";
        cout << P_Array[0].AT << "\t";
    }
    else
    {
        cout << P_Array[0].AT << "\t\t";
    }

    for (int i = 0; i < T_Process; i++)
    {
        if (i != 0 && P_Array[i - 1].CT < P_Array[i].AT)
        {
            cout << P_Array[i].AT << "\t\t";
        }
        cout << P_Array[i].CT << "\t\t";
    }
    cout << "\n";
}

void Chart(Process P_Array[], int T_Process)
{
    cout << "Various Time's Related To Process Scheduling\n\n";
    cout << "+---------------------------------------------------------------------------------------------------------------+\n";
    cout << "|\tProcess\t|\tAT\t|\tBT\t|\tCT\t|\tWT\t|\tTAT\t|\tRT      |\n";
    cout << "+---------------------------------------------------------------------------------------------------------------+\n";
    for (int i = 0; i < T_Process; i++)
    {
        cout << "|\t" << P_Array[i].P_Name << "\t|\t" << P_Array[i].AT
             << "\t|\t" << P_Array[i].BT << "\t|\t" << P_Array[i].CT
             << "\t|\t" << P_Array[i].WT << "\t|\t" << P_Array[i].TAT
             << "\t|\t" << P_Array[i].RT << "\t|\n";
    }
    cout << "+---------------------------------------------------------------------------------------------------------------+\n";
}

void New_Process_Array(Process P_Array[], Process N_P_Array[], int T_Process)
{
    sort(P_Array, P_Array + T_Process, mycomp);
    bool isProcessed[T_Process] = {0};
    int Timer = P_Array[0].AT;
    for (int i = 0; i < T_Process; i++)
    {
        int p_no = -1;
        for (int j = 0; j < T_Process; j++)
        {
            if (Timer >= P_Array[j].AT && isProcessed[j] == 0)
            {
                if (p_no == -1)
                {
                    p_no = j;
                }
                if (p_no != -1 && P_Array[p_no].BT < P_Array[j].BT)
                {
                    p_no = j;
                }
            }
        }
        if (p_no == -1) // when the process has gaps
        {
            for (int j = 0; j < T_Process; j++)
            {
                if (isProcessed[j] == 0)
                {
                    p_no = j;
                    break;
                }
            }
        }
        isProcessed[p_no] = 1;
        N_P_Array[i] = P_Array[p_no];
        if (Timer < P_Array[p_no].AT)
        {
            Timer += (P_Array[p_no].AT - Timer);
        }
        Timer += P_Array[p_no].BT;
    }
}

void LJF(Process P_Array[], int T_Process)
{
    Process N_P_Array[T_Process];
    New_Process_Array(P_Array, N_P_Array, T_Process);

    int Timer = 0;
    for (int i = 0; i < T_Process; i++)
    {

        if (Timer < N_P_Array[i].AT)
        {
            Timer += (N_P_Array[i].AT - Timer);
        }
        Timer += N_P_Array[i].BT;

        N_P_Array[i].CT = Timer;

        N_P_Array[i].TAT = N_P_Array[i].CT - N_P_Array[i].AT;

        N_P_Array[i].WT = N_P_Array[i].TAT - N_P_Array[i].BT;

        N_P_Array[i].RT = N_P_Array[i].WT;
    }
    Print_Bars();
    Chart(N_P_Array, T_Process);
    Print_Bars();
    Print_Bars();
    GanttChart(N_P_Array, T_Process);
    Print_Bars();
    Print_Bars();
    Average_Time(N_P_Array, T_Process);
    Print_Bars();
}

int main()
{
    system("cls");
    Print_Bars();
    cout << "20BCS070_Vicky_Gupta\n";
    cout << "Largest Job First Process Scheduling Alogorithm\n";
    Print_Bars();
    int T_Process;
    cout << "Enter The No Of Processes : ";
    cin >> T_Process;
    fflush(stdin);
    Process P_Array[T_Process];
    Print_Bars();
    cout << "Enter The Process Details...\n";
    cout << "| Process Name | Arival Time | Burst Time | \n";

    for (int i = 0; i < T_Process; i++)
    {
        cin >> P_Array[i].P_Name;
        cin >> P_Array[i].AT;
        cin >> P_Array[i].BT;
    }

    LJF(P_Array, T_Process);
    Print_Bars();
    cout << "Exited..\n";
    Print_Bars();
    return 0;
}

/*

Input
Pname AT BT
4
P1 0 2
P2 1 3
P3 2 5
P4 3 7


ProcessID	Arrival		Burst
4
P1            1           2
P2            2           4
P3            3           6
P4            4           8
*/