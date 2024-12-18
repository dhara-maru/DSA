// power using recursion
#include <stdio.h>
int power_rec(int base, int exponent) {
    if (exponent == 0)
        return 1;  // Base case: any number to the power of 0 is 1
    return base * power_rec(base, exponent - 1);  // Recursive case
}

int main() {
    int base, exponent;

    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exponent);

    printf("Result using recursion: %d\n", power_rec(base, exponent));

    return 0;
}
