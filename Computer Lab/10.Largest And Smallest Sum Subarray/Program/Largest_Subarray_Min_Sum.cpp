#include <iostream>
using namespace std;

void Largest_Subarray_Min_Sum(int n, int arr[])
{
    int minsum = arr[0], left = 0, right = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0, len = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (minsum >= sum)
            {
                
                if (right - left < j - i||minsum!=sum)
                {
                    left = i;
                    right = j;
                }
                minsum = sum;
            }
        }
    }
    cout << "Minimum Sum : " << minsum << endl
         << endl;
    cout << "Largest Subarray : \n";
    for (int i = left; i <= right; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Smallest_Subarray_With_Largest_Sum(int n, int arr[])
{
    int maxsum = arr[0], left = 0, right = n;
    for (int i = 0; i < n; i++)
    {
        int sum = 0, len = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (maxsum <= sum)
            {
                if (right - left > j - i||maxsum!=sum)
                {
                    left = i;
                    right = j;
                }
                maxsum = sum;
            }
        }
    }
    cout << "Maximum Sum : " << maxsum << endl
         << endl;
    cout << "Minimum Subarray : \n";
    for (int i = left; i <= right; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    system("cls");
    cout << "___Vicky_Gupta_20BCS070___" << endl;
    int n;
    cout << "Enter The Length Of The Array : \n";
    cin >> n;
    int arr[n];
    cout << "Enter The Elments Of The Array : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl
         << endl;
    Largest_Subarray_Min_Sum(n, arr);
    cout << endl;
    Smallest_Subarray_With_Largest_Sum(n, arr);
    return 0;
}