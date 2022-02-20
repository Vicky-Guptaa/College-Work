#include <stdio.h>
#include <stdbool.h>
struct Student
{
    char Name[100];
    int Roll_No;
    float Sub_1, Sub_2, Sub_3, Percentage;
};

void Insert_Row()
{
    printf("Insert Operation Is Selected...\n");
    FILE *fptr;
    fptr = fopen("Data.txt", "a");
    if (fptr == NULL)
    {
        printf("Error In Opening File!");
        return;
    }
    struct Student Stud;
    printf("Enter The Name : ");
    fflush(stdin);
    gets(Stud.Name);
    printf("Enter The Roll No : ");
    scanf("%d", &Stud.Roll_No);
    printf("Enter The Marks Of Subject 1 : ");
    scanf("%f", &Stud.Sub_1);
    printf("Enter The Marks Of Subject 2 : ");
    scanf("%f", &Stud.Sub_2);
    printf("Enter The Marks Of Subject 3 : ");
    scanf("%f", &Stud.Sub_3);
    Stud.Percentage = (Stud.Sub_1 + Stud.Sub_2 + Stud.Sub_3) / 3;
    int num = 4;
    fwrite(&Stud, sizeof(Stud), 1, fptr);
    fclose(fptr);
    printf("\nRecord Inserted Successfully!\n");
}

void Display()
{
    printf("Display...\n");
    FILE *fptr;
    fptr = fopen("Data.txt", "r");
    if (fptr == NULL)
    {
        printf("Error In Opening File!\n");
        return;
    }
    struct Student Temp;
    printf("| Name | Roll No | Subject 1 | Subject 2 | Subject 3 | Percentage |\n\n");
    while (fread(&Temp, sizeof(Temp), 1, fptr))
    {
        printf("%s\t%d\t%.2f\t%.2f\t%.2f\t%.2f\n", Temp.Name, Temp.Roll_No, Temp.Sub_1, Temp.Sub_2, Temp.Sub_3, Temp.Percentage);
    }
    fclose(fptr);
}

void Remove_Row()
{
    FILE *fptr = NULL, *tptr = NULL;
    fptr = fopen("Data.txt", "r");
    if (fptr == NULL)
    {
        printf("Error In Opening File!\n");
        return;
    }
    tptr = fopen("temp.txt", "a");
    printf("Remove Operation Is Selected...\n");
    int Roll_No;
    printf("Enter The Roll No Of Student : ");
    scanf("%d", &Roll_No);
    struct Student Temp;
    bool Found = false;
    while (fread(&Temp, sizeof(Temp), 1, fptr))
    {
        if (Roll_No == Temp.Roll_No)
        {
            Found = true;
            continue;
        }
        fwrite(&Temp, sizeof(Temp), 1, tptr);
    }
    fclose(fptr);
    fclose(tptr);
    remove("Data.txt");
    rename("temp.txt", "Data.txt");
    if (Found == false)
        printf("\nNo Such Roll No Found In Data Base\n");
    else
        printf("\nRow Successfully Removed!\n");
}

void Update_Row()
{
    FILE *fptr = NULL, *tptr = NULL;
    fptr = fopen("Data.txt", "r");
    if (fptr == NULL)
    {
        printf("Error In Opening File!\n");
        return;
    }
    tptr = fopen("temp.txt", "a");
    printf("Update Operation Is Selected...\n");
    int Roll_No;
    printf("Enter The Roll No Of Student : ");
    scanf("%d", &Roll_No);
    struct Student Temp;
    bool Found = false;
    while (fread(&Temp, sizeof(Temp), 1, fptr))
    {
        if (Roll_No == Temp.Roll_No)
        {
            Found = true;
            printf("Enter The Name : ");
            fflush(stdin);
            gets(Temp.Name);
            printf("Enter The Roll No : ");
            scanf("%d", &Temp.Roll_No);
            printf("Enter The Marks Of Subject 1 : ");
            scanf("%f", &Temp.Sub_1);
            printf("Enter The Marks Of Subject 2 : ");
            scanf("%f", &Temp.Sub_2);
            printf("Enter The Marks Of Subject 3 : ");
            scanf("%f", &Temp.Sub_3);
            Temp.Percentage = (Temp.Sub_1 + Temp.Sub_2 + Temp.Sub_3) / 3;
        }
        fwrite(&Temp, sizeof(Temp), 1, tptr);
    }
    fclose(fptr);
    fclose(tptr);
    remove("Data.txt");
    rename("temp.txt", "Data.txt");
    if (Found == false)
        printf("\nNo Such Roll No Found In Data Base\n");
    else
        printf("\nRow Successfully Updated!\n");
}

void Menu()
{
    printf("___Operation___\n");
    printf("1.Insert Row\n");
    printf("2.Remove Row\n");
    printf("3.Update Row\n");
    printf("4.Display\n");
    printf("5.Exit\n\n");
    printf("Enter Your Choice : ");
}

int Options()
{
    int opt;
    fflush(stdin);
    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
        Insert_Row();
        break;
    case 2:
        Remove_Row();
        break;
    case 3:
        Update_Row();
        break;
    case 4:
        Display();
        break;
    case 5:
        return 0;
    default:
        printf("Incorrect Input!\nTry Again!\n");
        break;
    }

    return 1;
}

int main()
{
    system("cls");
    while (1)
    {
        Menu();
        if (!Options())
            break;
    }
    return 0;
}