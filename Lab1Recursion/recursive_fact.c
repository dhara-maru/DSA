//factorial using recursion
#include <stdio.h>
int findfact(int n){
    if(n==0 || n==1){
        return 1;
    }
    else{
        return n * findfact(n-1);
    }
}
void main(){
    int i,n,factorial;
    printf("Enter a number : ");
    scanf("%d",&n);
    printf("Factorial of %d is %d",n,findfact(n));
}