// Write a program to find common elements between two arrays.
#include <stdio.h>
void main(){
    int arr1[5];
    int length1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[5];
    int length2 = sizeof(arr2) / sizeof(arr2[0]);
    
    for(int i=0; i<5; i++){
        printf("\nEnter array 1 elem %d  :",(i+1));
        scanf("%d",&arr1[i]);
    }

    printf("\nArray 1: ");
    for(int i=0; i<5; i++){
        printf("%d \t",arr1[i]);
        
    }

    for(int i=0; i<5; i++){
        printf("\nEnter array 2 elem %d  :",(i+1));
        scanf("%d",&arr2[i]);
    }

    printf("\nArray 2: ");
    for(int i=0; i<5; i++){
        printf("%d \t",arr2[i]);
        
    }

    printf("\nCommon Elements : \n");
    for(int i=0; i<length1; i++){
        for(int j=0; j<length2; j++){
            if(arr1[i] == arr2[j]){
                printf("%d\n",arr1[i]);
                break;
            }
           
        }
       
    }
}