// Read n numbers in an array and print it in ascending order.
#include <stdio.h>
void main(){
    int arr[5];
    int length = sizeof(arr) / sizeof(arr[0]);
    
    for(int i=0; i<5; i++){
        printf("Enter array elem %d  :",(i+1));
        scanf("%d",&arr[i]);
    }

    printf("Array : ");
    for(int i=0; i<5; i++){
        printf("%d \t",arr[i]);
        
    }

    printf("\nArray after sorting : ");
    for(int i=0; i<length - 1; i++){
        for(int j=0; j<length-i-1; j++){
            if (arr[j] > arr[j+1]) {
                int temp=arr[j];
                arr[j] = arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0; i<5; i++){
        printf("%d \t",arr[i]);
        
    }

}