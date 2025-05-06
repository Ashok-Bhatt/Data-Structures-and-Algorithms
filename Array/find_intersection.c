#include <stdio.h>

void Arrayintersection(int arr1[], int m, int arr2[], int n){
    
    printf("\nArray intersection: ");
    int i=0, j=0;

    while (i<m && j<n){
        if (arr2[j]>arr1[i]){
            i++;
        }
        else if (arr2[j]<arr1[i]){
            j++;
        }
        else{
            printf("%d ",arr1[i]);
            i++;
            j++;
        }
    }
    printf("\n");
}

int main(void) {
    int array3[10] = {1,2,3,4,5,6,7,8,9,10};
    int array4[8] = {11,21,41,81,91,121,601,1001};
    Arrayintersection(array3,10,array4,8);   
    return 0;
}