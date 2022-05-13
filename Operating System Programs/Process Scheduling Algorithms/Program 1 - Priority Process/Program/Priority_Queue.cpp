#include <iostream>
#include <string.h>
using namespace std;

struct Priority_Queue
{
    char process_name[4];
    int priority;
    Priority_Queue *next;
};

void isEmpty(int size)
{
    cout << "isEmpty...\n";
    if (size == 0)
        cout << "Empty" << endl;
    else
        cout << "Not Empty" << endl;
}

void Display(Priority_Queue *head, int size)
{
    cout << "Display...\n";
    if (size == 0)
    {
        cout << "Queue Is Empty" << endl;
        return;
    }
    while (head != nullptr)
    {
        cout << "|" << head->process_name << "|" << head->priority << "|"
             << "-->";
        head = head->next;
    }
    cout << "Null\n";
    cout << endl;
}

void Process_Initialized(Priority_Queue *&new_process)
{
    cout << "Enter The Priority : ";
    cin >> new_process->priority;
    fflush(stdin);
    cout << "Enter The Process Name : ";
    gets(new_process->process_name);
    new_process->next = nullptr;
}

void Insert_Process(Priority_Queue *&head, Priority_Queue *&tail, int &size)
{
    cout << "Insert Process...\n";
    Priority_Queue *new_process = (Priority_Queue *)malloc(1 * sizeof(Priority_Queue));
    if (new_process == nullptr)
    {
        cout << "Memory Not Assigned" << endl;
        return;
    }
    size++;

    Process_Initialized(new_process);

    Priority_Queue *temp = head;
    if (head == nullptr)
    {
        head = new_process;
        tail = new_process;
    }
    else
    {
        if (temp->priority > new_process->priority)
        {
            new_process->next = head;
            head = new_process;
        }
        else if (tail->priority <= new_process->priority)
        {
            tail->next = new_process;
            tail = tail->next;
        }
        else
        {
            while (temp && temp->next)
            {
                if (temp->next->priority > new_process->priority)
                {
                    new_process->next = temp->next;
                    temp->next = new_process;
                    break;
                }
                temp = temp->next;
            }
        }
    }
    Display(head, size);
}

void Execute_Process(Priority_Queue *&head, int &size)
{
    cout << "Execute_Process...\n";
    if (size == 0)
    {
        cout << "Queue Underflow" << endl;
        return;
    }
    cout << "|" << head->process_name << "|" << head->priority << "|"
         << "\n";
    size--;
    Priority_Queue *todelete = head;
    head = head->next;
    delete todelete;
    Display(head, size);
}

void Total_Process(int size)
{
    cout << "Total No Of Process : " << size << endl;
}

void Bars()
{
    cout << "---------------------------------------------------------------\n";
}
bool Options(Priority_Queue *&head, Priority_Queue *&tail, int &size)
{
    int opt;
    cin >> opt;
    Bars();
    switch (opt)
    {
    case 1:
        Insert_Process(head, tail, size);
        break;
    case 2:
        Execute_Process(head, size);
        break;
    case 3:
        Total_Process(size);
        break;
    case 4:
        Display(head, size);
        break;
    case 5:
        cout << "Exit...\n";
        return 0;
    default:
        cout << "Invalid Input!\nTry Again!\n";
    }
    Bars();
    return 1;
}

void Menu()
{
    cout << "_____Priority Scheduling Algorithm_____ \n";
    cout << "1.Insert Process \n";
    cout << "2.Execute \n";
    cout << "3.Total No Of Process \n";
    cout << "4.Display \n";
    cout << "5.Exit \n";
    cout << "Enter Your Choice : ";
}

int main()
{

    system("cls");
    cout << "_____Vicky_Gupta_20BCS070_____\n\n";
    int size = 0;
    Priority_Queue *head = nullptr, *tail = nullptr;
    while (true)
    {
        Menu();
        if (!Options(head, tail, size))
            break;
    }
    cout << "Exiting...\n";
    Bars();
    return 0;
}