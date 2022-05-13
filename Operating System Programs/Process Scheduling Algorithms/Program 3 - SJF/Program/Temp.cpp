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
        return P1.BT < P2.BT;
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
        cout << "|     |  ";
    }
    else
    {
        cout << "|  ";
    }

    for (int i = 0; i < T_Process; i++)
    {
        if (i != 0 && P_Array[i - 1].CT < P_Array[i].AT)
        {
            cout << "    |   ";
        }
        cout << P_Array[i].P_Name << "  |   ";
    }
    cout << "\n";

    if (P_Array[0].AT != 0)
    {
        cout << " 0     ";
        cout << P_Array[0].AT << "     ";
    }
    else
    {
        cout << P_Array[0].AT << "      ";
    }

    for (int i = 0; i < T_Process; i++)
    {
        if (i != 0 && P_Array[i - 1].CT < P_Array[i].AT)
        {
            cout << P_Array[i].AT << "      ";
        }
        cout << P_Array[i].CT << "      ";
    }
    cout << "\n";
}

void Chart(Process P_Array[], int T_Process)
{
    cout << "Various Time's Related To Process Scheduling\n\n";
    cout << "|  Process   |  AT  |  BT  |   CT   |   WT  |  TAT  |  RT  |\n";
    for (int i = 0; i < T_Process; i++)
    {
        cout << "   " << P_Array[i].P_Name << "\t\t" << P_Array[i].AT
             << "\t" << P_Array[i].BT << "\t" << P_Array[i].CT
             << "\t" << P_Array[i].WT << "\t" << P_Array[i].TAT
             << "\t" << P_Array[i].RT << "\n";
    }
}

void SJF(Process P_Array[], int T_Process)
{
    // sort(P_Array, P_Array + T_Process, mycomp);
    int Timer = P_Array[0].AT;
    bool isProcessed[T_Process] = {0};
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
                if (p_no != -1 && P_Array[p_no].BT > P_Array[j].BT)
                {
                    p_no = j;
                }
            }
        }
        isProcessed[p_no] = 1;
        if (Timer < P_Array[p_no].AT)
        {
            Timer += (P_Array[p_no].AT - Timer);
        }
        Timer += P_Array[p_no].BT;

        P_Array[p_no].CT = Timer;

        P_Array[p_no].TAT = P_Array[p_no].CT - P_Array[p_no].AT;

        P_Array[p_no].WT = P_Array[p_no].TAT - P_Array[p_no].BT;

        P_Array[p_no].RT = P_Array[p_no].WT;
    }
    Print_Bars();
    Chart(P_Array, T_Process);
    Print_Bars();
    Print_Bars();
    GanttChart(P_Array, T_Process);
    Print_Bars();
    Print_Bars();
    Average_Time(P_Array, T_Process);
    Print_Bars();
}

int main()
{
    system("cls");
    Print_Bars();
    cout << "20BCS070_Vicky_Gupta\n";
    cout << "Shortest Job First Process Scheduling Alogorithm\n";
    Print_Bars();
    int T_Process;
    cout << "Enter The No Of Processes : ";
    cin >> T_Process;
    fflush(stdin);
    Process P_Array[T_Process];
    Print_Bars();
    cout << "Enter The Process Details...\n";
    cout << "| Process Name | Burst Time | Arival Time | \n";

    for (int i = 0; i < T_Process; i++)
    {
        cin >> P_Array[i].P_Name;
        cin >> P_Array[i].AT;
        cin >> P_Array[i].BT;
    }

    SJF(P_Array, T_Process);
    Print_Bars();
    cout << "Exited..\n";
    Print_Bars();
    return 0;
}

/*

Input
Pname AT BT
P1 1 7
P2 2 5
P3 3 1
P4 4 2
P5 5 8
*/