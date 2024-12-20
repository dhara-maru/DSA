// 2. Create an array of structure Student_Detail (Enrollment_no, Name, Sem, CPI) for 5 students, scan their information and print it.
#include <stdio.h>

struct Student_Detail {
    int Enrollment_no;
    char Name[50];
    int Sem;
    float CPI;
};

int main() {
    struct Student_Detail studs[2];

    for (int i = 0; i < 2; i++) {
        printf("Enter Enrollment Number for Student %d: ", i + 1);
        scanf("%d", &studs[i].Enrollment_no);

        printf("Enter Name for Student %d: ", i + 1);
        scanf("%s", studs[i].Name);

        printf("Enter Semester for Student %d: ", i + 1);
        scanf("%d", &studs[i].Sem);

        printf("Enter CPI for Student %d: ", i + 1);
        scanf("%f", &studs[i].CPI);
    }

    // Print student details
    printf("\nStudent Details:\n");
    for (int i = 0; i < 2; i++) {
        printf("Student %d:\n", i + 1);
        printf("Enrollment Number: %d\n", studs[i].Enrollment_no);
        printf("Name: %s\n", studs[i].Name);
        printf("Semester: %d\n", studs[i].Sem);
        printf("CPI: %.2f\n", studs[i].CPI);
        printf("-----------------------\n");
    }

    return 0;
}
