#include <iostream>
using namespace std;
void spiral(int n, int m, int mat[100][100])
{

    int rows = 0, rowe = n - 1, cols = 0, cole = m - 1;

    int total = n * m;

    cout << endl
         << "Helical Order Of The Input Matrix : " << endl;

    while (total > 0)
    {
        for (int i = cols; i <= cole && total-- > 0; i++)
        {
            cout << mat[rows][i] << " ";
        }
        rows++;

        for (int i = rows; i <= rowe && total-- > 0; i++)
        {
            cout << mat[i][cole] << " ";
        }
        cole--;

        for (int i = cole; i >= cols && total-- > 0; i--)
        {
            cout << mat[rowe][i] << " ";
        }
        rowe--;

        for (int i = rowe; i >= rows && total-- > 0; i--)
        {
            cout << mat[i][cols] << " ";
        }
        cols++;
    }
    cout << endl;
}
int main()
{
    int n1, n2;
    cout << "enter your size of array" << endl;
    cin >> n1;
    cout << "enter your size of array" << endl;
    cin >> n2;
    int a[100][100];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    spiral(n1, n2, a);

    return 0;
}