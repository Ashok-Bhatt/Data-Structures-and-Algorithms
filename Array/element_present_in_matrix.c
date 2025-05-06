#include <stdio.h>

void arrayInput(int row, int column, int array[][column]){
    printf("\nEnter the matrix elements:\n");
    for (int i=0; i<row; i++){
        for (int j=0; j<column; j++){
            scanf("%d",&array[i][j]);
        }
    }
}

void arrayOutput(int row, int column, int array[][column]){
    printf("\nThe matrix elements are:\n");
    for (int i=0; i<row; i++){
        for (int j=0; j<column; j++){
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
}

void ColumnOutput(int row, int column, int array[][column]){
    printf("\nThe matrix elements in column wise order are:\n");
    for (int i=0; i<column; i++){
        for (int j=0; j<row; j++){
            printf("%d ",array[j][i]);
        }
        printf("\n");
    }
}

void ColumnInput(int row, int column, int array[][column]){
    printf("\nEnter matrix elements in column wise order:\n");
    for (int i=0; i<column; i++){
        for (int j=0; j<row; j++){
            scanf("%d",&array[j][i]);
        }
    }
}

int main(void) {

    /*     
        int array1[2][3];
        arrayInput(2, 3, array1);
        arrayOutput(2, 3, array1);
        ColumnOutput(2, 3, array1);

        int array2[2][5];
        ColumnInput(2, 5, array2);
        arrayOutput(2, 5, array2);
        ColumnOutput(2, 5, array2);
    */

    // Problem 01: Check whether an element is in the array or not:
    int array1[10][10];
    int row, column, key, flag=0;
    printf("\nEnter the number of rows, number of columns in the matrix and the key required:");
    scanf("%d %d %d\n", &row, &column, &key);

    arrayInput(row, column, array1);

    for (int i=0; i<row; i++){
        for (int j=0; i<column; j++){
            if (array1[i][j]==key){
                flag = 1;
                break;
            }
        }
    }

    if (flag==1){
        printf("\n%d is present in the array.",key);
    }
    else{
        printf("\n%d is not present in the array.",key);
    } 
    
    return 0;
}