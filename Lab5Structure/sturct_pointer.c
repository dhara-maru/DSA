// 3. Create a structure Employee_Detail (Employee_id, Name, Designation, Salary). Write a program to read the detail from user and print it using Structure Pointer.
#include <stdio.h>
struct Employee_Detail{
    int Employee_id;
    char Name[50];
    char Designation[50];
    float Salary;
};
int main(){
    struct Employee_Detail e1 = {101, "Dhara M.", "Tester", 5000.0};
    struct Employee_Detail e2 = {102, "Hetvi M.", "Developer", 10000.0};

    struct Employee_Detail *ptr1 = &e1;
    struct Employee_Detail *ptr2 = &e2;

    printf("Employee 1 name : %s \n", ptr1->Name);
    printf("Employee 2 Designation : %s \n", ptr2->Designation);

    printf("Employee 1 ID : %d \n", ptr1->Employee_id);
    printf("Employee 2 Salary : %.2f \n", ptr2->Salary);

    return 0;
}