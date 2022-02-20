#include <iostream>
using namespace std;

int Length(char str[])
{
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

int Vowels(char str[])
{
    int len = Length(str);
    int vowels = 0;
    for (int i = 0; i < len; i++)
    {

        if (str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E' ||
            str[i] == 'i' || str[i] == 'I' || str[i] == 'o' || str[i] == 'O' ||
            str[i] == 'u' || str[i] == 'U')
            vowels++;
    }
    return vowels;
}

void Remove_Extra_Space(char paragraph[])
{
    int length = Length(paragraph);
    for (int i = 1; i < length; i++)
    {
        if (paragraph[i] == ' ' && paragraph[i] == paragraph[i - 1])
        {
            for (int j = i; j < length; j++)
            {
                paragraph[j - 1] = paragraph[j];
            }
            length--;
            i--;
            paragraph[length] = '\0';
        }
    }
}

int Count_Spaces(char paragraph[])
{
    int length = Length(paragraph);
    int spaces = 0;
    for (int i = 0; i < length; i++)
    {
        if (paragraph[i] == ' ')
            spaces++;
    }
    return spaces;
}

int Count_Tabs(char paragraph[])
{
    int length = Length(paragraph);
    int tabs = 0;
    for (int i = 0; i < length; i++)
    {
        if (paragraph[i] == 9)
            tabs++;
    }
    return tabs;
}

int Count_Sentences(char paragraph[])
{
    int length = Length(paragraph);
    int sentence = 0;
    for (int i = 0; i < length; i++)
    {
        if (paragraph[i] == '.')
            sentence++;
    }
    return sentence;
}

int Count_Lines(char paragraph[])
{
    int length = Length(paragraph);
    int lines = 1;
    for (int i = 0; i < length; i++)
    {
        if (paragraph[i] == '\n')
            lines++;
    }
    return lines;
}

void Bars()
{
    cout << "-----------------------------------------------------------------------" << endl;
}
int main()
{
    system("cls");
    cout << "_____Vicky_Gupta_20BCS070_____" << endl
         << endl;
    char paragraph[300];
    cout << "Enter A Paragraph : " << endl;
    cin.getline(paragraph, 300, '$');

    cout << endl;
    int vowels = Vowels(paragraph);
    int length = Length(paragraph);
    int spaces = Count_Spaces(paragraph);
    int tabs = Count_Tabs(paragraph);
    int lines = Count_Lines(paragraph);
    int sentence = Count_Sentences(paragraph);

    Bars();
    cout << "No Of Spaces : " << spaces << endl;
    cout << "No Of Tabs : " << tabs << endl;
    cout << "No Of Sentence : " << sentence << endl;
    cout << "No Of Lines : " << lines << endl;
    cout << "No Of Vowels : " << vowels << endl
         << endl;
    Bars();
    cout << "Extra Spaces Removed : " << endl;

    Remove_Extra_Space(paragraph);
    cout << paragraph << endl;
    Bars();
    return 0;
}