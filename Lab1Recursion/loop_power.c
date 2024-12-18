//power using loop
#include <stdio.h>
int findpower(int base, int exponent){
    int result=1;
     for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}
void main(){
   int base, exponent;

    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exponent);

     printf("Result using loop: %d\n", findpower(base, exponent));
}