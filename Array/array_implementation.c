#include <stdio.h>

void printArray(int num2[], int length){
    for (int i=0; i<length; i++){
        printf("%d ",num2[i]);
    }
}

int main(void) {
    
    int num[10];
    printf("\nThe number at index 0 is %d",num[0]);

    int num1[3] = {2,4,5};
    printf("\nThe number at index 1 is %d",num1[1]);

    int num2[7] = {2,4,6,10};
    printf("\nThe number at index 2 is %d",num2[2]);

    printf("\n");
    int length = sizeof(num2)/sizeof(int);
    printArray(num2,length);
    
    return 0; 
}