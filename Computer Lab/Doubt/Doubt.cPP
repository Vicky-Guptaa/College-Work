#include <iostream>
using namespace std;
struct employee
{
    int id;
    int w;
    int h;
} Emps[3];
int c = -1;
struct employee addEmployee()
{
    struct employee Emp;

    printf("Enter Employee ID->");
    scanf("%d", &Emp.id);

    printf("Enter Employee height->");
    scanf("%d", &Emp.w);

    printf("Enter Employee weight->");
    scanf("%d", &Emp.h);

    printf("Successfully Inserted!!");
    return Emp;
}

void displayAllEmployees(struct employee Emps[], int employeeCount)
{

    printf("\n-----------------------------------------------------------------------");
    if (employeeCount != 0)
        for (int i = 0; i < employeeCount; i++)
        {
            cout << "id->" << Emps[i].id << endl;
            cout << "weight->" << Emps[i].w
                 << endl;
            cout << "height->" << Emps[i].h << endl;
            printf("\n-----------------------------------------------------------------------");
        }
    else
        printf("No Employees Exist!!!");
}
int main()
{
    struct employee Emps[3];
    int ch = 0;
    int employeeCount = 0;
    while (ch != 4)
    {
        cout << "\n1stands for add employee" << endl;
        cout << "\n2stands for display all" << endl;
        cout << "enter your choice " << endl;
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            Emps[employeeCount++] = addEmployee();
            break;
        case 2:
            displayAllEmployees(Emps, employeeCount);
            break;
        }
    }
    return 0;
}