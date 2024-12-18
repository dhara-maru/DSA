//copy the array
#include <stdio.h>

void main() {
    int arr[5];
    int length = sizeof(arr) / sizeof(arr[0]);
    int arr2[length];

    for (int i = 0; i < 5; i++) {
        printf("Enter array 1 element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }


    for (int i = 0; i < length; i++) {
        arr2[i] = arr[i];
    }

   printf("Array 1 : ");
    for (int i = 0; i < length; i++) {
        printf("%d\t",arr[i]);
    }
    printf("Array 2 : ");
    for (int i = 0; i < length; i++) {
        printf("%d\t",arr2[i]);
    }
}
