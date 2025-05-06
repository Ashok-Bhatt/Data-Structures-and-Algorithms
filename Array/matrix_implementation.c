#include <stdio.h>

int main(void) {

    int array1[2][3] = {1,2,3,4,5,6};
    int array2[2][3] = {{2,4,6},{3,6,9}};

    printf("\nArray 1:\n");
    for (int i=0; i<2; i++){
        for (int j=0; j<3; j++){
            printf("%d ",array1[i][j]);
        }
        printf("\n");
    }

    printf("\nArray 2:\n");
    for (int i=0; i<2; i++){
        for (int j=0; j<3; j++){
            printf("%d ",array2[i][j]);
        }
        printf("\n");
    }

return 0;
}