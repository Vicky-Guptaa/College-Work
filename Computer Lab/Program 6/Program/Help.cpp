#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int i, j, f = 0, k;
    char str1[200];
    cout << "enter your string" << endl;
    gets(str1);
    char str2[200];
    cout << "enter your string" << endl;
    gets(str2);
    int l1 = 0, l2 = 0;
    for (int i = 0; str1[i] != '\0'; i++)
    {
        l1++;
    }

    for (int i = 0; str2[i] != '\0'; i++)
    {
        l2++;
    }
    bool check = false;
    for (int i = 0; i <= l1 - l2; i++)
    {
        k = i;
        for (j = 0; j < l2; j++)
        {
            if (str2[j] != str1[k])
            {
                break;
            }
            k++;
        }
        if (j == l2)
        {
            check = true;
            cout << "Found" << endl;
        }
    }

    if (check == false)
    {
        cout << "Not found" << endl;
    }
    return 0;
}