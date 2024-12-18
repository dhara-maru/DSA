//find gcd of 2 nums using a loop
#include <stdio.h>
int findgcd(int n1, int n2){
    while(n2 != 0){
        int temp = n2;
        n2 = n1 % n2;
        n1 = temp;
    }
    return n1;
}
void main(){
    int n1,n2;
    printf("Enter 2 nums : ");
    scanf("%d %d",&n1,&n2);

    int gcd = findgcd(n1,n2);
    printf("GCD of %d and %d is : %d", n1,n2,gcd);
}