// 1. Create a structure Employee_Detail (Employee_id, Name, Designation, Salary). Write a program to read the detail from user and print it.
#include <stdio.h>
struct Employee_Detail{
    int Employee_id;
    char Name[50];
    char Designation[50];
    float Salary;
};

void main(){
    struct Employee_Detail e1 = {101, "Dhara M.", "Tester", 5000.00};
    struct Employee_Detail e2 = {102, "Hetvi M.", "UI Designer", 6000.00};
    struct Employee_Detail e3 = {103, "Riya M.", "Developer", 7000.00};

printf("Employee Details : \n");

    printf("%d\t | %s\t | %s\t | %.2f\t \n",e1.Employee_id, e1.Name, e1.Designation, e1.Salary);
    printf("%d\t | %s\t | %s\t | %.2f\t \n",e2.Employee_id, e2.Name, e2.Designation, e2.Salary);
    printf("%d\t | %s\t | %s\t | %.2f\t \n",e3.Employee_id, e3.Name, e3.Designation, e3.Salary);


}