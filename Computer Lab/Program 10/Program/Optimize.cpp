#include <iostream>
using namespace std;

void Largest_Subarray_Min_Sum(int n, int arr[])
{
    int minsum = arr[0], s = 0, left = 0, right = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum <= minsum)
        {
            if (right - left < i - s || minsum != sum)
            {
                left = s;
                right = i;
            }
            minsum = sum;
        }
        if (sum > 0)
        {
            s = i + 1;
            sum = 0;
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
    int maxsum = arr[0], s = 0, left = 0, right = 0, sum = 0;
    ;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum >= maxsum)
        {
            if (right - left > i - s || maxsum != sum)
            {
                left = s;
                right = i;
            }
            maxsum = sum;
        }
        if (sum < 0)
        {
            s = i + 1;
            sum = 0;
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