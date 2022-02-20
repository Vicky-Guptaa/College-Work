#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Answer(int arr[], int s, int n)
{
    if (s >= n - 1)
        return 0;
    int Min = 1e9;
    for (int i = 1; i <= arr[s]; i++)
        Min = min(Min, 1 + Answer(arr, s + i, n));
    return Min;
}

int main()
{
    int arr[] = {1, 1, 1, 0, 1, 1};
    cout << Answer(arr, 0, 6) << "\n";
    return 0;
}