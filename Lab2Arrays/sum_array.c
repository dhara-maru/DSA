//sum and average of array elems
#include <stdio.h>

void main() {
    int arr[5];
    
    for (int i = 0; i < 5; i++) {
        printf("Enter array element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int length = sizeof(arr) / sizeof(arr[0]);

    int sum = 0;

    for (int i = 0; i < length; i++) {
        sum += arr[i];
    }

    double avg = (double)sum / length;

    printf("Array: ");
    for (int i = 0; i < length; i++) {
        printf("%d\t", arr[i]);
    }

    printf("\nSum of array is: %d\n", sum);
    printf("Average of array is: %.2lf\n", avg);
}
