#include<iostream>
using namespace std;

struct student
{
    int roll;
    int mark;
    char gender;
};

int main(){
    student*ptr=(student*)malloc(5*sizeof(student));
    ptr[1].gender='c';
    return 0;
}