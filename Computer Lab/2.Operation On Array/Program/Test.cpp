#include <iostream>
using namespace std;
#define size 40

int InputNum()
{
    int newnum;
    cout << "Enter The Number : ";
    cin >> newnum;
    return newnum;
}

int InsertBeg(int arr[], int n)
{
    if (n == size)
    {
        cout << "Array Overflow!" << endl;
        return n;
    }

    n++;
    for (int i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = InputNum();
    return n;
}

int InsertEnd(int arr[], int n)
{
    if (n == size)
    {
        cout << "Array Overflow!" << endl;
        return n;
    }

    arr[n] = InputNum();
    n++;
    return n;
}

int InsertK(int arr[], int n)
{
    if (n == size)
    {
        cout << "Array Overflow!" << endl;
        return n;
    }
    int k;
    cout << "Enter The Position [ Accoring To 1 Based Indexing ] : ";
    cin >> k;
    if (k > n + 1)
    {
        cout << "Invalid Input!" << endl;
        return n;
    }

    n++;
    for (int i = n; i >= k; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[k - 1] = InputNum();
    return n;
}

int DeleteBeg(int arr[], int n)
{
    if (n == 0)
    {
        cout << "Array Underflow!" << endl;
        return n;
    }
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    n--;
    return n;
}

int DeleteEnd(int arr[], int n)
{
    if (n == 0)
    {
        cout << "Array Underflow!" << endl;
        return n;
    }
    n--;
    return n;
}

int DeleteK(int arr[], int n)
{
    if (n == 0)
    {
        cout << "Array Underflow!" << endl;
        return n;
    }
    int k;
    cout << "Enter The Position [ Accoring To 1 Based Indexing ] : ";
    cin >> k;
    if (k > n)
    {
        cout << "Invalid Input!" << endl;
        return n;
    }
    for (int i = k; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    n--;
    return n;
}

int DeleteMulti(int arr[], int n)
{
    if (n == 0)
    {
        cout << "Array Underflow!" << endl;
        return n;
    }
    int del;
    cout << "Enter The Element To Be Deleted : ";
    cin >> del;
    bool chk = true;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == del)
        {
            chk = false;
            for (int j = i + 1; j < n; j++)
            {
                arr[j - 1] = arr[j];
            }
            i--;
            n--;
        }
    }
    if (chk)
        cout << "No Element Found In The Array" << endl;
    return n;
}

void Print(int arr[], int n)
{
    if (n == 0)
    {
        cout << "Array Is Empty!" << endl;
        return;
    }
    cout << "Array -> ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "    Size -> " << n;
    cout << endl;
}

void ShowMenu()
{
    cout << endl
         << "___Operations To Perform On Array___" << endl;
    cout << "1.Insert At The Beginning" << endl;
    cout << "2.Insert At The Kth Position" << endl;
    cout << "3.Insert At The End" << endl;
    cout << "4.Delete At The Beginning" << endl;
    cout << "5.Delete At The Kth Position" << endl;
    cout << "6.Delete At The End" << endl;
    cout << "7.Delete Particular Element" << endl;
    cout << "8.Exit" << endl;
    cout << "Enter Your Choice : ";
}

bool Options(int arr[], int *n)
{
    int opt;
    cin >> opt;
    if (opt >= 1 && opt <= 8)
    {
        cout << endl
             << "Operation " << opt << " Is Seleceted." << endl;
    }
    switch (opt)
    {
    case 1:
        *n = InsertBeg(arr, *n);
        break;
    case 2:
        *n = InsertK(arr, *n);
        break;
    case 3:
        *n = InsertEnd(arr, *n);
        break;
    case 4:
        *n = DeleteBeg(arr, *n);
        break;
    case 5:
        *n = DeleteK(arr, *n);
        break;
    case 6:
        *n = DeleteEnd(arr, *n);
        break;
    case 7:
        *n = DeleteMulti(arr, *n);
        break;
    case 8:
        return 0;
        break;
    default:
        cout << "Invalid Input!" << endl;
    }

    return 1;
}

int main()
{
    system("cls");
    int n;
    cout << "Enter The Size Of The Array : ";
    cin >> n;
    int arr[size];
    cout << "Enter The Element Of Array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    while (true)
    {
        ShowMenu();
        if (!Options(arr, &n))
        {
            break;
        }
        Print(arr, n);
        cout << endl;
    }
    cout<<"Exiting..."<<endl;
    return 0;
}
