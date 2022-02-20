#include <iostream>
using namespace std;

int Leap_Year_Count(int year, int month)
{
    if (month <= 2)
        year--;
    return year / 4 - year / 100 + year / 400;
}

int Month_Days_Count(int month)
{
    int Day_In_Month[12] = {31, 28, 31, 30, 31, 30,
                            31, 31, 30, 31, 30, 31};
    int Days = 0;
    for (int i = 0; i < month - 1; i++)
        Days += Day_In_Month[i];
    return Days;
}

int main()
{
    system("cls");
    cout << "_____Vicky_Gupta_20BCS070_____" << endl;
    cout << "Enter The Two Dates Sepearted By Special Characters : \n";
    char dates[100];
    gets(dates);
    int len = 0;
    while (dates[len] != '\0')
        len++;

    int day[2] = {0}, month[2] = {0}, year[2] = {0};

    int no_of_dates = 0, it = 0;

    while (no_of_dates < 2)
    {
        int multi = 10;

        while (dates[it] >= '0' && dates[it] <= '9')
        {
            day[no_of_dates] += (dates[it] - '0') * multi;
            multi /= 10;
            it++;
        }
        it++;
        multi = 10;
        while (dates[it] >= '0' && dates[it] <= '9')
        {
            month[no_of_dates] += (dates[it] - '0') * multi;
            multi /= 10;
            it++;
        }
        it++;
        multi = 1000;
        while (dates[it] >= '0' && dates[it] <= '9' && it < len)
        {
            year[no_of_dates] += (dates[it] - '0') * multi;
            multi /= 10;
            it++;
        }
        it++;
        no_of_dates++;
    }
    long long Days_Till_first = (long long)year[0] * 365;

    Days_Till_first += Month_Days_Count(month[0]);
    Days_Till_first += Leap_Year_Count(year[0], month[0]);
    Days_Till_first += day[0];

    long long Days_Till_Second = (long long)year[1] * 365;
    Days_Till_Second += day[1];
    Days_Till_Second += Month_Days_Count(month[1]);
    Days_Till_Second += Leap_Year_Count(year[1], month[1]);

    long long Count_Day = abs(Days_Till_first - Days_Till_Second);
    cout << "The No Of Days Between Given Dates : ";
    cout << Count_Day << endl;
    return 0;
}
