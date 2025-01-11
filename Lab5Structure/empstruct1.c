#include <stdio.h>
struct emp_detail{
    int id;
    char name[20];
    char designation[20];
    float salary;
};
void main(){
    struct emp_detail e;
    printf("Enter Employee ID : ");              
    scanf("%d", &e.id);
    printf("Enter Employee Name : ");
    scanf("%s", &e.name);
    printf("Enter Employee Designation : ");
    scanf("%s", &e.designation);
    printf("Enter Employee Salary : ");
    scanf("%f", &e.salary);


    printf("Emp ID : %d\n", e.id);
    printf("Emp Name : %s\n", e.name);
    printf("Emp Designation : %s\n", e.designation);
    printf("Emp Saalry : %.2f\n", e.salary);

}