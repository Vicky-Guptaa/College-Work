#include <iostream>
using namespace std;

void Highest_Mark(float stu_data[20][6], int n)
{
    cout << endl
         << "Task 2 Is Selected."
         << endl;
    float Max_Sub[3][2] = {0}; //roll no and marks
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Max_Sub[j][1] < stu_data[i][j + 2])
            {
                Max_Sub[j][0] = stu_data[i][0];
                Max_Sub[j][1] = stu_data[i][j + 2];
            }
        }
    }
    cout << "Roll No  |     Marks       |   Subject " << endl;
    for (int j = 0; j < 3; j++)
    {
        cout << Max_Sub[j][0] << "             " << Max_Sub[j][1] <<"               "<< j+1<<endl;
    }
}

void Highest_Percentage(float stu_data[20][6], int n)
{
    cout << endl
         << "Task 3 Is Selected."
         << endl;
    float Max_Perc[2][3] = {0};// roll no age and percentage
    for (int i = 0; i < n; i++)
    {
        if (Max_Perc[0][2] < stu_data[i][5])
        {
            Max_Perc[0][0] = stu_data[i][0];
            Max_Perc[0][1] = stu_data[i][1];
            Max_Perc[0][2] = stu_data[i][5];
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (Max_Perc[0][2] == stu_data[i][5])
            count++;
    }
    cout << "Roll No" << endl;
    if (count == 1)
    {
        cout << Max_Perc[0][0] << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (Max_Perc[0][2] == stu_data[i][5] && Max_Perc[0][0] != stu_data[i][0])
        {
            Max_Perc[1][2] = stu_data[i][5];
            Max_Perc[1][0] = stu_data[i][0];
            Max_Perc[1][1] = stu_data[i][1];
        }
    }
    if (Max_Perc[0][1] == Max_Perc[1][1])
    {
        cout << Max_Perc[0][0] << endl;
        cout << Max_Perc[1][0] << endl;
    }
    else
    {
        if (Max_Perc[0][1] < Max_Perc[1][1])
        {
            cout << Max_Perc[0][1] << endl;
        }
        else
        {
            cout << Max_Perc[1][1] << endl;
        }
    }
}

void Show_Data(float stu_data[20][6], int n)
{
    cout << endl
         << "Task 1 Is Selected."
         << endl;
    cout << "Roll No  |  Percentage " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << int(stu_data[i][0]) << "            ";
        cout << stu_data[i][5]<<"%"<< endl;
    }
}

void Menu()
{
    cout << endl
         << endl
         << "_____________________Task To Perform______________________" << endl;
    cout << "1.Show Percentage of All Student Along With Thier Roll No." << endl;
    cout << "2.Highest Marks In Each Subject Along With Roll No." << endl;
    cout << "3.Highest Percentage." << endl;
    cout << "4.Exit" << endl;
    cout << "Enter Your Choices : ";
}

bool Option(float stu_data[20][6], int n)
{
    int opt;
    cin >> opt;
    switch (opt)
    {
    case 1:
        Show_Data(stu_data, n);
        break;

    case 2:
        Highest_Mark(stu_data, n);
        break;
    case 3:
        Highest_Percentage(stu_data, n);
        break;
    case 4:
        return 0;
    default:
        cout << "Invalid_Entry" << endl;
    }
    return 1;
}

int main()
{
    system("cls");
    cout << "_________Vicky Gupta 20BCS070__________" << endl
         << endl;
    int n;
    cout << "Enter The No Of Students In Class : ";
    cin >> n;
    float stu_data[20][6];
    for (int i = 0; i < n; i++)
    {
        cout << endl
             << "Enter The Info Of Student " << i + 1 << "." << endl;
        cout << "Enter The Roll No Of The Student : ";
        cin >> stu_data[i][0];
        cout << "Enter The Age Of The Student : ";
        cin >> stu_data[i][1];
        float prcntge = 0;
        for (int j = 2; j < 5; j++)
        {
            cout << "Enter The Marks Of The Subject " << j - 1 << " : ";
            cin >> stu_data[i][j];
            prcntge += stu_data[i][j];
        }
        stu_data[i][5] = prcntge / 3;
    }

    while (true)
    {
        Menu();
        if (!Option(stu_data, n))
            break;
    }
    cout << "Exiting..." << endl;
    return 0;
}