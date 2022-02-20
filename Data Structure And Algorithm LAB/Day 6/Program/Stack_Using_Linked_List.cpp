#include <iostream>
using namespace std;
struct stack
{
    int data;
    stack *next;
} * top;

void Display()
{
    cout << "Display...\n";
    if (top == nullptr)
    {
        cout << "Stack Is Empty" << endl;
        return;
    }
    cout << "\n";
    stack *temp = top;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void Push()
{
    cout << "Push...\n";
    stack *newnode = (stack *)malloc(sizeof(stack));
    if (newnode == nullptr)
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    cout << "Enter The Number : ";
    cin >> newnode->data;
    newnode->next = top;
    top = newnode;
    cout << "\n";
    Display();
}

void Pop()
{
    cout << "Pop...\n";
    if (top == nullptr)
    {
        cout << "Stack Underflow" << endl;
        return;
    }
    cout << top->data << "\n";
    stack *todelete = top;
    top = top->next;
    delete todelete;
    cout << "\n";
    Display();
}

void Top()
{
    cout << "Top...\n";
    if (top == nullptr)
    {
        cout << "Stack Is Empty" << endl;
        return;
    }
    cout << top->data << "\n";
}

void isEmpty()
{
    cout << "isEmpty...\n";
    if (top != nullptr)
    {
        cout << "Not Empty \n";
    }
    else
    {
        cout << "Empty \n";
    }
}

void Total_Elements()
{
    cout << "Total Elements...\n";
    int total = 0;
    stack *temp = top;
    while (temp != nullptr)
    {
        total++;
        temp = temp->next;
    }
    cout << total << "\n";
}

int Options()
{
    int opt;
    cin >> opt;
    switch (opt)
    {
    case 1:
        Push();
        break;
    case 2:
        Pop();
        break;
    case 3:
        isEmpty();
        break;
    case 4:
        Top();
        break;
    case 5:
        Total_Elements();
        break;
    case 6:
        Display();
        break;
    case 7:
        cout << "Exit...\n";
        return 0;
    default:
        cout << "Invalid Input!\nTry Again!\n";
    }
    return 1;
}

void Menu()
{
    cout << "_____Operations_On_Stacks_____ \n";
    cout << "1.Push \n";
    cout << "2.Pop \n";
    cout << "3.isEmpty \n";
    cout << "4.Top \n";
    cout << "5.Total Elements \n";
    cout << "6:Display \n";
    cout << "7.Exit \n";
    cout << "Enter Your Choice : ";
}

int main()
{
    system("cls");

    while (true)
    {
        Menu();
        if (!Options())
            break;
    }
    return 0;
}