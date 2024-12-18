// Read n numbers in an array then read two different numbers, replace 1st number with 2nd number in an array and print the final array.
#include <stdio.h>

void main() {
    int size, oldnum, newnum;
  
    printf("\nEnter array size: ");
    scanf("%d", &size);

    int arr[size];

    for(int i = 0; i < size; i++) {
        printf("\nEnter element %d: ", (i + 1));
        scanf("%d", &arr[i]);
    }

 
    printf("\nEnter element you want to change: ");
    scanf("%d", &oldnum);

    printf("\nEnter the new number for it: ");
    scanf("%d", &newnum);

    
    for(int i = 0; i < size; i++) {
        if(arr[i] == oldnum) {
            arr[i] = newnum;
            break;  
        }
    }

    printf("\nUpdated array: ");
    for(int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
}
