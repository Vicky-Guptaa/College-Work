#include <iostream>
#include <string.h>
using namespace std;
int Max_Size = 0;
struct Employee
{
    int Eid;
    char Name[30];
    float Salary;
};

void Add_Employee(Employee *Emp_Data, int &size)
{
    cout << endl
         << "Add Employee..." << endl;
    if (size == Max_Size)
    {
        cout << "Overflow" << endl;
        return;
    }
    int Eid;
    bool check = false;
    do
    {
        cout << "Enter The Employee Eid : ";
        cin >> Eid;
        for (int i = 0; i < size; i++)
        {
            if (Eid == (Emp_Data + i)->Eid)
            {
                cout << endl
                     << "Eid Already Exist!" << endl;
                cout << "Try Again!" << endl
                     << endl;
                check = true;
            }
        }
    } while (check);

    (Emp_Data + size)->Eid = Eid;
    fflush(stdin);
    cout << "Enter The Employee Name : ";
    gets((Emp_Data + size)->Name);
    cout << "Enter The Employee Salary : ";
    cin >> (Emp_Data + size)->Salary;
    size++;
}

void Display_Employee(Employee *Emp_Data, int &size)
{
    if (size == 0)
    {
        cout << endl
             << "Empty!" << endl;
        return;
    }
    cout << endl
         << "Display All Employee..." << endl;
    cout << "|\tEid \t|"
         << "\t    Name     \t|"
         << "\t Salary \t|" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "\t" << (Emp_Data + i)->Eid << "\t";
        cout << "\t" << (Emp_Data + i)->Name << "\t";
        cout << "\t" << (Emp_Data + i)->Salary << "\t" << endl;
    }
}

void Search_Employee_Eid(Employee *Emp_Data, int &size)
{
    cout << endl
         << "Search Employee By Eid..." << endl;
    if (size == 0)
    {
        cout << "Empty!" << endl;
        return;
    }
    int Eid;
    cout << "Enter The Employee Eid : ";
    cin >> Eid;
    int i;
    cout << endl;
    for (i = 0; i < size; i++)
    {
        if ((Emp_Data + i)->Eid == Eid)
        {
            cout << "Employee Found!\n\nDetails..." << endl;
            cout << "Eid : " << (Emp_Data + i)->Eid << "\t  ";
            cout << "Name : " << (Emp_Data + i)->Name << "\t  ";
            cout << "Salary : " << (Emp_Data + i)->Salary << endl;
            break;
        }
    }
    if (i == size)
    {
        cout << "Employee Not Found!" << endl;
    }
}

void Search_Employee_Name(Employee *Emp_Data, int &size)
{
    cout << endl
         << "Search Employee By Name..." << endl;
    if (size == 0)
    {
        cout << "Empty!" << endl;
        return;
    }
    char Name[30];
    cout << "Enter The Name Of Your Employee : ";
    fflush(stdin);
    gets(Name);
    int i;
    cout << endl;
    for (i = 0; i < size; i++)
    {
        int j;
        if (!strcmp(Name, (Emp_Data + i)->Name))
        {
            cout << "Employee Found!\n\nDetails..." << endl;
            cout << "Eid : " << (Emp_Data + i)->Eid << "\t  ";
            cout << "Name : " << (Emp_Data + i)->Name << "\t  ";
            cout << "Salary : " << (Emp_Data + i)->Salary << endl;
            break;
        }
    }
    if (i == size)
    {
        cout << "Employee Not Found!" << endl;
    }
}

void Highest_Salary(Employee *Emp_Data, int &size)
{
    cout << endl
         << "Highest Salary Of Employee" << endl;
    if (size == 0)
    {
        cout << "Empty!" << endl;
        return;
    }
    float Max_Salary = 0;
    for (int i = 0; i < size; i++)
    {
        if (Max_Salary < (Emp_Data + i)->Salary)
        {
            Max_Salary = (Emp_Data + i)->Salary;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (Max_Salary == (Emp_Data + i)->Salary)
        {
            cout << "Eid : " << (Emp_Data + i)->Eid << "\t  ";
            cout << "Name : " << (Emp_Data + i)->Name << "\t ";
            cout << "Salary : " << (Emp_Data + i)->Salary << endl;
        }
    }
}

void Total_Employee(int &size)
{
    cout << endl
         << "No Of Employee..." << endl;
    cout << endl
         << "Total No Of Employee : ";
    cout << size << endl;
}

void Menu()
{
    cout << endl
         << endl
         << "___Operations___" << endl;
    cout << "1.Add Employee" << endl;
    cout << "2.Display Employee" << endl;
    cout << "3.Search Employee Byy Eid" << endl;
    cout << "4.Search Employee By Name" << endl;
    cout << "5.Employee having Higest Salary" << endl;
    cout << "6.Total No Of Employee" << endl;
    cout << "7.Exit" << endl;
    cout << "Enter Your Choice : ";
}

bool Options(Employee *Emp_Data, int &size)
{
    int opt;
    cin >> opt;
    switch (opt)
    {
    case 1:
        Add_Employee(Emp_Data, size);
        break;
    case 2:
        Display_Employee(Emp_Data, size);
        break;
    case 3:
        Search_Employee_Eid(Emp_Data, size);
        break;
    case 4:
        Search_Employee_Name(Emp_Data, size);
        break;
    case 5:
        Highest_Salary(Emp_Data, size);
        break;
    case 6:
        Total_Employee(size);
        break;
    case 7:
        return 0;
    default:
        cout << "Invalid Input!\nTry Again!" << endl;
    }
    return 1;
}

int main()
{
    system("cls");
    cout << "__Vicky Gupta 20BCS070__" << endl;

    cout << "Enter The No Of Employee : ";
    cin >> Max_Size;

    struct Employee *Emp_Data = (Employee *)malloc(Max_Size * sizeof(Employee));

    int size = 0;

    while (true)
    {
        Menu();
        if (!Options(Emp_Data, size))
            break;
    }
    cout << endl
         << "Exiting..." << endl;
    return 0;
}