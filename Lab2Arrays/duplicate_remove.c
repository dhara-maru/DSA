#include <stdio.h>

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    if (size <= 0) return;
    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    sortArray(arr, size);

    int sorted = 1;
    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[sorted - 1]) {
            arr[sorted++] = arr[i];
        }
    }

    printf("Sorted array after removing duplicate elements:\n");
    for (int i = 0; i < sorted; i++) {
        printf("%d\n", arr[i]);
    }
}
