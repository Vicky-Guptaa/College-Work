#include <iostream>
using namespace std;

char Decimal_Hexadecimal_values(int n)
{
    if (n < 10)
    {
        return n + 48;
    }
    else
    {
        return 55 + n;
    }
}

int Hexadecimal_Decimal_Value(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return ch - '0';
    }
    else
    {
        return ch - 55;
    }
}

void Decimal_Hexadecimal()
{
    cout << endl;
    cout << "Decimal To Hexadecimal Selected..." << endl;
    cout << "Enter A Decimal Number : ";
    int n;
    cin >> n;
    char str[20];
    int i = 0, num = n;

    while (n > 0)
    {
        char ch = Decimal_Hexadecimal_values(n % 16);
        str[i++] = ch;
        n /= 16;
    }
    str[i] = '\0';

    cout << "Hexadecimal Value : ";
    for (int j = i - 1; j >= 0; j--)
    {
        cout << str[j];
    }
    cout << endl;
}

void Hexadecimal_Decimal()
{
    cout << endl;
    cout << "Hexadecimal To Decimal Selected..." << endl;
    cout << "Enter A Hexadecimal Number : ";
    char str[20];
    fflush(stdin);
    gets(str);
    int len = 0;
    while (str[len] != '\0')
        len++;
    int Decimal = 0, pwr = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        Decimal += pwr * Hexadecimal_Decimal_Value(str[i]);
        pwr *= 16;
    }
    cout << "Decimal Value : ";
    cout << Decimal << endl
         << endl;
    
}

void Menu()
{
    cout << endl
         << endl;
    cout << "_______Conversion_______" << endl;
    cout << "1.Decimal To Hexadecimal" << endl;
    cout << "2.Hexadecimal To Decimal" << endl;
    cout << "3.Exit" << endl;
    cout << "Enter Your Choice : ";
}

bool Options()
{
    int opt;
    fflush(stdin);
    cin >> opt;
    switch (opt)
    {
    case 1:
        Decimal_Hexadecimal();
        break;
    case 2:
        Hexadecimal_Decimal();
        break;
    case 3:
        return 0;
    default:
        cout << "\nInvalid Choice!\nTry Again! " << endl;
    }
    return 1;
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
    cout << "Exiting..." << endl;
    return 0;
}