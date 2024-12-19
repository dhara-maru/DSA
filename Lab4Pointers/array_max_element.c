// Write a program to find largest element in the array using Pointer.
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

    

    int *max = arr;
    for(int i=0; i<size; i++){
        if(arr[i] > *max){
            max = &arr[i];
        }
    }

    printf("Largest element : %d", *max);

}