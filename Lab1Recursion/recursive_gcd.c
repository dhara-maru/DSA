//GCD using recursion
#include <stdio.h>
int findgcd(int a, int b){
    if(b==0){
        return a; // Base case: When b is 0, GCD is a.
    return findgcd(b, a % b); // Recursive case.
    }
}
void main(){
    int a,b;
    printf("Enter 2 nums : ");
    scanf("%d %d",&a, &b);

    int gcd = findgcd(a,b);
    printf("GCD of %d and %d is %d",a,b,gcd);
}