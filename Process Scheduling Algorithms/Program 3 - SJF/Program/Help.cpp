#include <iostream>
#include <string.h>
using namespace std;
int s = 0;
struct node *head = nullptr;
struct node *tail = nullptr;
struct node
{
    char n[4];
    int pr;
    int brs;
    int comple_time = 0;
    int turn_aro_time = 0;
    int response_time = 0;
    int wait_tume = 0;
    struct node *next;
};
void insert(int s)
{

    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == nullptr)
    {
        cout << "No memory present" << endl;
        return;
    }
    else
    {
        s++;
        cout << "Enter your priority" << endl;
        int p;
        cin >> p;
        fflush(stdin);
        cout << "Enter your process" << endl;
        char n[20];
        gets(n);
        cout << "Enter your brust time" << endl;
        int brs;
        cin >> brs;
        ptr->pr = p;
        strcpy(ptr->n, n);
        ptr->brs = brs;
        ptr->next = nullptr;
        struct node *temp = head;
        if (head == nullptr)
        {
            head = ptr;
            tail = ptr;
        }
        else
        {
            if (temp->pr > ptr->pr)
            {
                ptr->next = head;
                head = ptr;
            }
            else if (tail->pr <= ptr->pr)
            {
                tail->next = ptr;
                tail = tail->next;
            }
            else
            {
                while (temp)
                {
                    if (temp->next->pr > ptr->pr)
                    {
                        ptr->next = temp->next;
                        temp->next = ptr;
                        break;
                    }
                    temp = temp->next;
                }
            }
        }
    }
    ptr = head;
    int n[90] = {0}, i = 1;

    while (ptr != nullptr)
    {
        ptr->comple_time = n[i - 1] + ptr->brs;
        n[i] += ptr->comple_time;
        ptr->turn_aro_time = ptr->comple_time - ptr->pr;
        ptr->wait_tume = ptr->turn_aro_time - ptr->brs;
        ptr->response_time = ptr->wait_tume;
        ptr = ptr->next;
        i++;
    }
}

void display(struct node *head)
{
    int i = 0;

    cout << "PROCESS NAME | "
         << "ARRIVAL TIME | "
         << "BRUST TIME | "
         << " | "
         << "COMPLETION TIME"
         << " | "
         << "TAT"
         << " | "
         << "WT"
         << " | "
         << "RT" << endl;
    int avg_tat = 0, avg_wt = 0, avg_rt = 0;
    while (head != nullptr)
    {
        // head->avg_response+=head->wait_tume/i;
        cout << head->n << " | " << head->pr << " | " << head->brs << " | " << head->comple_time << " | " << head->turn_aro_time << " | " << head->wait_tume << " | " << head->response_time << endl;

        avg_rt += head->response_time;
        avg_wt += head->wait_tume;
        avg_tat += head->turn_aro_time;
        head = head->next;
        i++;
    }
    avg_rt /= i;
    avg_wt /= i;
    avg_tat /= i;

    cout << "average_rt"
         << " -> " << avg_rt << "\n";
    cout << "average_wt"
         << " -> " << avg_wt << "\n";
    cout << "average_Tat"
         << " -> " << avg_tat << "\n";
}
int main()
{

    int ch = 0;
    while (ch != 5)
    {
        cout << "\n1. INSERT \n2. EXECUTE \n3. display \n4 TOTAL OPERATIONS \n5.EXIT IT" << endl;
        cout << "Enter your choice" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            insert(s);
            display(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            break;
        }
    }
    return 0;
}