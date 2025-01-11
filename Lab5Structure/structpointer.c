#include <stdio.h>
struct emp_detail{
    int id;
    char name[20];
    char designation[20];
    float salary;
};
void main(){
    struct emp_detail e[3];
    
for(int i=0; i<3; i++){
 
    printf("\nEnter emp id : ");
    scanf("%d", &e[i].id);
    printf("\nEnter Name : ");
    scanf("%s", &e[i].name);
    printf("\nEnter Designation : ");
    scanf("%d", &e[i].designation);
    printf("\nEnter Salary : ");
    scanf("%f", &e[i].salary);
    
    }

    struct emp_detail *ptr = e;
  
   for(int i=0; i<3; i++){
    printf("\n===========================================");
    printf("\nEmp id of emp %d : %d\n", i+1, ptr->id);
    printf("\nName of emp %d : %s\n",i+1, ptr->name);
    printf("\ndesignation of emp %d : %d\n", i+1, ptr->designation);
    printf("\nsalary of emp %d : %.2f\n", i+1, ptr->salary);
    printf("\n===========================================");
    ptr++;
    }


}