#include <stdio.h>
struct stud_detail{
    int enroll;
    char name[20];
    int sem;
    float CPI;
};
void main(){
    struct stud_detail s[5];
    for(int i=0; i<5; i++){
    printf("Enter Enrollment Number : ");
    scanf("%d", &s[i].enroll);
    printf("Enter Name : ");
    scanf("%s", &s[i].name);
    printf("Enter Semester : ");
    scanf("%d", &s[i].sem);
    printf("Enter Student CPI : ");
    scanf("%f", &s[i].CPI);

    }

    for(int i=0; i<5; i++){
    printf("\n===========================================");
    printf("\nEnrollment Number of student %d : %d\n", i+1, s[i].enroll);
    printf("\nName of student %d : %s\n",i+1, s[i].name);
    printf("\nSemester of student %d : %d\n", i+1, s[i].sem);
    printf("\nCPI of student %d : %.2f\n", i+1, s[i].CPI);
    printf("\n===========================================");
    }

}