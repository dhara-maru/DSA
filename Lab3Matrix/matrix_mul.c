// Read two matrices, first 3x2 and second 2x3, perform multiplication operation and store result in third matrix and print it.
#include <stdio.h>

void main() {
    int m1[3][2]; // First matrix: 3x2
    int m2[2][3]; // Second matrix: 2x3
    int res[3][3]; // Resultant matrix: 3x3

    //matrix 1
    printf("Enter elements for matrix 1 (3x2):\n");
    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 2; j++) { 
            printf("Enter elem for matrix 1 [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &m1[i][j]);
        }
    }

    printf("\n");

    //matrix 2
    printf("Enter elements for matrix 2 (2x3):\n");
    for (int i = 0; i < 2; i++) { 
        for (int j = 0; j < 3; j++) { 
            printf("Enter elem for matrix 2 [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &m2[i][j]);
        }
    }

    printf("\n");

   
    for (int i = 0; i < 3; i++) {         // Rows of first matrix
        for (int j = 0; j < 3; j++) {     // Columns of second matrix
            res[i][j] = 0;               
            for (int k = 0; k < 2; k++) { // Common dimension
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    // Printing the resultant matrix
    printf("Multiplied matrix (3x3):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", res[i][j]); 
        }
        printf("\n");
    }
}
