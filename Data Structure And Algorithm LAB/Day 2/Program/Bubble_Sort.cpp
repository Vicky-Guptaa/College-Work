#include <iostream>
using namespace std;
#define size 1000

void Swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void Bubble_Sort(int arr[], int n)
{
        cout << endl
         << "Given Array -> ";
    PrintArray(arr, n);
    for (int i = 1; i < n; i++)
    {
        cout << endl
             << "Pass -> " << i << endl<<endl;
        for (int j = 1; j < n + 1 - i; j++)
        {
            cout<< "Iteration No -> " << j << endl;
            if (arr[j - 1] > arr[j])
                Swap(arr, j, j - 1);
                PrintArray(arr, n);
        }
    }
}

int main()
{
    system("cls");
    cout<<"______20BCS070 Vicky Gupta_____"<<endl;
    cout<<"__________Bubble Sort__________"<<endl<<endl;
    int n, arr[size];
    
    cout << "Enter The Size Of The Array : ";
    cin >> n;
    
    cout << "Enter The Elements Of The Array : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
        
    Bubble_Sort(arr, n);
    
    cout << endl
         << "Sorted Array -> ";
    
    PrintArray(arr, n);
    cout<<endl;
    return 0;
}