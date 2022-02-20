#include <stdio.h>
#include <iostream>
using namespace std;
int strlen(char s[100])
{
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

void display(char s[100])
{
    for (int i = 0; i < strlen(s); i++)
    {
        printf("%c", s[i]);
    }
}

void Strrev(char s1[100])
{
    char task;
    int x=0;
    for (int i = 0; s1[i] != '\0'; i++)
    {
        x++;
    }
    for (int i = 0; i < (x / 2); i++)
    {
        task = s1[i];
        s1[i] = s1[x - i - 1];
        s1[x - i - 1] = task;
    }
    for (int i = 0; i < x; i++)
    {
        printf("%c", s1[i]);
    }
}

void Strcpy(char s2[100], char r2[100])
{
    printf("\n1st string before copy : ");
    display(s2);
    printf("\n2nd string before copy : ");
    display(r2);
    for (int i = 0; i < strlen(s2); i++)
    {
        r2[i] = s2[i];
    }
    printf("\n2nd string after copy : ");
    display(r2);
}

bool Strcmp(char s2[100], char r2[100])
{
    if (strlen(s2) != strlen(r2))
    {
        return false;
    }
    else
    {
        for (int i = 0; i < strlen(s2); i++)
        {
            if (s2[i] != r2[i])
            {
                return false;
            }
        }
    }
    return true;
}

void concadenate(char s5[100], char r5[100])
{
    printf("\n1st string before concadenate : ");
    display(s5);
    printf("\n2nd string after concadenate : ");
    display(r5);
    int k = 0;
    for (int i = 0; i < strlen(s5); i++)
    {
        ++k;
    }
    s5[k] = ' ';
    k++;
    for (int i = 0; i < strlen(r5); i++)
    {
        s5[k] = r5[i];
        k++;
    }
    printf("\n1st string after concadenate : ");
    display(s5);
}

bool palindrome(char s3[100])
{
    for (int i = 0; i < strlen(s3); i++)
    {
        if (s3[i] != s3[strlen(s3) - i - 1])
        {
            return false;
        }
    }
    return true;
}

int Search(char s4[100], char r4[100])
{
    int k = 0, temp = 0;
    ;
    for (int i = 0; i < strlen(s4); i++)
    {
        if (s4[i] == r4[0])
        {
            k = i;
        }
    }
    temp = k;
    for (int i = 0; i < strlen(r4); i++)
    {
        if (r4[i] != s4[k])
        {
            return -1;
        }
        k++;
    }
    return temp;
}

int main()
{
    printf("Press 1 to find the length of string.\n");
    printf("Press 2 to Reverse the string.\n");
    printf("Press 3 to copy the string to other.\n");
    printf("Press 4 to compare two string.\n");
    printf("Press 5 to Concatenate one string to other.\n");
    printf("Press 6 to check wheather the string is palindrome or not.\n");
    printf("Press 7 to Search substring from a given string.\n");
    printf("Press 8 to Exit.\n");
    int n;
    int res;
    bool result;
    char q[100];
    char r[100];
    while (n != 8)
    {
        printf("\nEnter your choice.\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter the string : ");
            fflush(stdin);
            cin.getline(q,100);
            //				cin.getline(q, 100);
            printf("%d", strlen(q));
            break;
        case 2:
            printf("Enter the string : ");
            fflush(stdin);
            cin.getline(q,100);
            Strrev(q);
            break;
        case 3:
            printf("Enter the string : ");
            fflush(stdin);
            cin.getline(q,100);
            Strcpy(q, r);
            break;
        case 4:
            printf("Enter the 1st string : ");
            fflush(stdin);
            cin.getline(q,100);
            printf("Enter the 2nd string : ");
            cin.getline(r,100);
            result = Strcmp(q, r);
            if (result)
            {
                printf("Strings are equal.\n");
            }
            else
            {
                printf("Strings are not equal.\n");
            }
            break;
        case 5:
            printf("Enter the 1st string : ");
            fflush(stdin);
            cin.getline(q,100);
            printf("Enter the 2nd string : ");
            cin.getline(r,100);
            concadenate(q, r);
            break;
        case 6:
            printf("Enter the string : ");
            fflush(stdin);
            cin.getline(q,100);
            result = palindrome(q);
            if (result)
            {
                printf("String is palindrome.\n");
            }
            else
            {
                printf("String is not palindrome.\n");
            }
            break;
        case 7:
            printf("Enter the 1st string : ");
            fflush(stdin);
            cin.getline(q,100);
            printf("Enter the 2nd string : ");
            cin.getline(r,100);
            res = Search(q, r);
            if (res == -1)
            {
                printf("String not found.\n");
            }
            else
            {
                printf("String found at index %d.", res);
            }
            break;
        case 8:
            printf("\n\n		EXIT.\n\n");
            break;
        }
    }
    return 0;
}