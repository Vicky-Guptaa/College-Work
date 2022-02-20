#include <iostream>
using namespace std;

int matrix[10][10];
int n=0, m=0;

void Print_Matrix()
{
    cout << endl
         << "____Matrix___" << endl<<endl;;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << "    ";
        }
        cout << endl;
    }
}

void Print_Helical()
{
    if(n==0||m==0)
    {
        cout<<endl<<"Matrix Input First!"<<endl;
        return;
    }
    cout << endl
         << "Operation Helical Order Is Selected." << endl;

    Print_Matrix();

    int rows = 0, rowe = n - 1, cols = 0, cole = m - 1;

    int total = n * m;

    cout << endl
         << "Helical Order Of The Input Matrix : " << endl;

    while (total > 0)
    {
        for (int i = cols; i <= cole && total-- > 0; i++)
        {
            cout << matrix[rows][i] << " ";
        }
        rows++;

        for (int i = rows; i <= rowe && total-- > 0; i++)
        {
            cout << matrix[i][cole] << " ";
        }
        cole--;

        for (int i = cole; i >= cols && total-- > 0; i--)
        {
            cout << matrix[rowe][i] << " ";
        }
        rowe--;

        for (int i = rowe; i >= rows && total-- > 0; i--)
        {
            cout << matrix[i][cols] << " ";
        }
        cols++;
    }
    cout << endl;
}

void Input()
{
    cout << endl
         << "Opertion New Matrix Input Is Selected." << endl;
    cout << "Number Of Rows : ";
    cin >> n;

    cout << "Number Of Column : ";
    cin >> m;

    cout << "Enter The Element Of The Matrix : " << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

void Menu()
{
    cout << endl
         << "___Task To Performs___" << endl;
    cout << "1.New Matrix Input." << endl;
    cout << "2.Helical Order." << endl;
    cout << "3.Exit." << endl;
    cout << "Enter Your Choice : ";
}

bool Options()
{
    int opt;
    cin >> opt;
    switch (opt)
    {
    case 1:
        Input();
        break;
    case 2:
        Print_Helical();
        break;
    case 3:
        return 0;
    default:
        cout << "Invalid Input!\nTry Again!" << endl;
        break;
    }
    return 1;
}

int main()
{
    system("cls");
    cout << "__Vicky_Gupta_20BCS070__" << endl;
    while (true)
    {
        Menu();
        if (!Options())
            break;
    }
    cout << endl
         << "Exiting..." << endl;

    return 0;
}