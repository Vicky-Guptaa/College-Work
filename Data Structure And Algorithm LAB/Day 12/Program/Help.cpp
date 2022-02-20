#include <iostream>
using namespace std;
struct node *head = nullptr;
struct node
{
    struct node *pre;
    int data;
    struct node *next;
};
void insert()
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == nullptr)
    {
        cout << "LINKED LIST IS EMPTY" << endl;
    }
    else
    {
        int data;
        cout << "Enter your data" << endl;
        cin >> data;
        ptr->data = data;
        ptr->next = head;
        ptr->pre = nullptr;
        head = ptr;
    }
}
void display()
{
    struct node *ptr = head;
    if (head == nullptr)
    {
        cout << "Nothing to display " << endl;
        return;
    }
    else
    {
        cout << "\n!!! YOUR STACK!!!" << endl;
        while (ptr != nullptr)
        {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }
}
void insertlast()
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    if (ptr == nullptr)
    {
        cout << "Nothing to insert " << endl;
        return;
    }
    else
    {
        int data;
        cout << "Enter your data" << endl;
        cin >> data;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        ptr->data = data;
        ptr->next = nullptr;
        p->next = ptr;
    }
}
void insertatposition()
{
    struct node *p = head;
    struct node *q = head->next;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == nullptr)
    {
        cout << "Can't insert" << endl;
        return;
    }
    else
    {
        int i;
        cout << "Enter your index" << endl;
        cin >> i;
        int data;
        cout << "entre your data" << endl;
        cin >> data;
        int idx = 0;
        while (idx != i)
        {
            p = p->next;
            q = q->next;
            idx++;
        }
        ptr->data = data;
        ptr->next = q;
        p->next = ptr;
    }
}

void deletelast()
{
    struct node *p = head;
    struct node *q = head->next;
    if (head == nullptr)
    {
        cout << "Sorry,nothing to delete " << endl;
        return;
    }
    else
    {
        while (q->next != nullptr)
        {
            p == p->next;
            q == q->next;
        }
        p->next = nullptr;
        free(q);
    }
}
void deletefirst()
{
    struct node *p = head;
    struct node *q = head->next;
    if (head == nullptr)
    {
        cout << "Sorry,nothing to delete " << endl;
        return;
    }
    else
    {

        p->next = q->next;
        free(p);
        head = q;
    }
}
void search()
{
    int k = 0, f = 0;
    cout << "Enter your number which you want to find" << endl;
    cin >> k;
    struct node *ptr = head;
    while (ptr != nullptr)
    {
        if (k == ptr->data)
        {
            f = 1;
        }
        ptr = ptr->next;
    }
    if (f == 1)
    {
        cout << "Yes,I got it" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
}
void reverse()
{
    struct node *ptr;
    while (ptr->next != ptr->pre)
    {
        cout << ptr->data << endl;
    }
}
int main()
{
    int ch = 0;
    while (ch != 8)
    {
        cout << "\n1. Insert at beg \n2. insert at last \n3. insert at position \n4. delete first \n5. delete last \n6 delete at position \n7. search \n8. Exit it" << endl;
        cout << "Enter your choice" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            insert();
            display();
            break;
        case 2:
            insertlast();
            display();
            break;
        case 3:
            insertatposition();
            display();
            break;
        case 4:
            deletefirst();
            display();
            break;
        case 5:
            deletelast();
            display();
            break;
        case 6:
            reverse();
            display();
            break;
        case 7:
            search();
            display();
            break;
        }
    }
    return 0;
}