//prime number between two intervals (range prime)
#include <stdio.h>
void main(){
    int r1,r2,i,n,j;
    printf("Enter starting n : ");
    scanf("%d",&r1);
    printf("Enter ending n : ");
    scanf("%d",&r2);

    for(j=r1; j<=r2; j++){
        int flag=1;
        for(i=2; i<j; i++){
            if(j%i==0){
                flag=0;
            }
        }
        if (flag)
        {
            printf("%d ,", i);
        }
    }

}