// Read two 2x2 matrices and perform addition of matrices into third matrix and print it.
#include <stdio.h>
void main(){
    int m1[2][2];
    int m2[2][2];
    int m3[2][2];

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            printf("Enter element [%d][%d] for matrix 1: ", i + 1, j + 1);
            scanf("%d",&m1[i][j]);
        }
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            printf("Enter element [%d][%d] for matrix 2: ", i + 1, j + 1);
            scanf("%d",&m2[i][j]);
        }
    }

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }

    printf("Added matrix : \n");
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            printf("%d\t", m3[i][j]);
        }
        printf("\n");
    }
}