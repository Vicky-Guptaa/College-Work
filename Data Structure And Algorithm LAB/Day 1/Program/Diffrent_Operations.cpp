#include <iostream>
using namespace std;

void Factorial()
{
    cout << endl
         << "Factorial Is Selected" << endl;
    int n, fact = 1;
    cout << "Enter A Number : ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    cout << "Factorial Of " << n << " : " << fact << endl
         << endl;
}

void Sum_Series()
{
    cout << endl
         << "Sum Series Is Selected" << endl;
    int n;
    cout << "Enter A Number : ";
    cin >> n;
    int sum = 0;
    cout << "Sum Series : ";
    for (int i = 1; i <= n; i++)
    {
        sum += i;
        cout << sum << " ";
    }
    cout << endl
         << endl;
}

void Fibonacci()
{
    cout << endl
         << "Fibonacci Is Selected" << endl;
    int n;
    cout << "Enter A Number : ";
    cin >> n;
    int num1 = -1, num2 = 1;
    cout << "Fibonacci Series : ";
    for (int i = 0; i < n; i++)
    {
        int num3 = num1 + num2;
        num1 = num2;
        num2 = num3;
        cout << num3 << " ";
    }
    cout << endl
         << endl;
}

void Power()
{
    cout << endl
         << "Power Of A And B Is Selected" << endl;
    int a, b;
    cout << "Enter Two Numbers : ";
    cin >> a >> b;
    int p = 1;
    for (int i = 0; i < b; i++)
    {
        p *= a;
    }
    cout << "Power Of " << a << " And " << b << " : " << p << endl
         << endl;
}

void Menu()
{
    cout<<"20BCS070 Vicky Gupta"<<endl;
    cout << "____Operations____" << endl;
    cout << "1.Factorial" << endl;
    cout << "2.Sum Of Series" << endl;
    cout << "3.Fibonacci Series" << endl;
    cout << "4.Power Of A And B" << endl;
    cout << "5.Exit" << endl;
    cout << "Enter Your Choice : ";
}

bool Operation()
{
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        Factorial();
        break;
    case 2:
        Sum_Series();
        break;
    case 3:
        Fibonacci();
        break;
    case 4:
        Power();
        break;
    case 5:
        return false;
    default:
        cout <<endl<< "Invalid Input Try Again!" << endl<<endl;

    }
    return true;
}

int main()
{
    system("cls");
    while (1)
    {
        Menu();
        if (!Operation())
            break;
    }
    return 0;
}