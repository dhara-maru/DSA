//largest elem in the array
#include <stdio.h>

void main() {
    int arr[5];
    
    for (int i = 0; i < 5; i++) {
        printf("Enter array element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int length = sizeof(arr) / sizeof(arr[0]);

    int max = arr[0];

    for (int i = 0; i < length; i++) {
        if(arr[i]> max){
            max = arr[i];
        }
    }

   
    printf("Max elem of array is %d", max);
}
