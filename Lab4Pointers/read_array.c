// Read n numbers in an array and print it using pointer.
#include <stdio.h>
void main(){
    
    int size;
    printf("Enter size : ");
    scanf("%d", &size);

    int arr[size];

    for(int i=0; i<size; i++){
        printf("Enter array element %d : ",(i+1));
        scanf("%d",&arr[i]);
    }

    printf("Printing them using a pointer :\n");

    int *ptr = arr;
    for(int i=0; i<size; i++){
        printf("%d\t",*ptr);
        ptr++;
    }

}