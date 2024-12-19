// Find transpose of a square matrix - transpose of matrix means swapping the row and column of the original matrix.
#include <stdio.h>
void main(){
    int m1[3][3];
    int m2[3][3];

    //original matrix
    printf("Enter elements for ORIGINAL matrix 1 (3x3):\n");
    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 3; j++) { 
            printf("Enter elem for matrix [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &m1[i][j]);
        }
    }

printf("Original Matrix : \n");

    for(int i=0; i<3; i++){
       for(int j=0; j<3; j++){
            printf("%d\t",m1[i][j]);
        } 
        printf("\n");
    }

    printf("\nTranspose of Original Matrix : \n");

    for(int i=0 ; i<3; i++){
        for(int j=0; j<3; j++){
            m2[j][i] = m1[i][j];
        }
    }

    for(int i=0; i<3; i++){
       for(int j=0; j<3; j++){
            printf("%d\t",m2[i][j]);
        } 
        printf("\n");
    }
}