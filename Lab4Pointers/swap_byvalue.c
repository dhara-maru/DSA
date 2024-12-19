// Write a C program to swap two numbers, calling an UDF by value.
#include <stdio.h>
void swap(int a, int b){

    printf("\nValue of a Before swapping : %d", a);
    printf("\nValue of b Before swapping : %d", b);

    int temp=a;
    a=b;
    b=temp;

    printf("\nValue of a after swapping : %d", a);
    printf("\nValue of b after swapping : %d", b);
}
void main(){
    int a,b;
    printf("Enter a and b numbers : ");
    scanf("%d %d",&a,&b);

    swap(a,b);

}