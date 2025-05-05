#include <limits.h>
#include <stdio.h>

int main() {
    // Problem 01: Find minimum and maximum element of an array
    int array[10]={2,4,2,5,7,10,12,3,0,-1}, maximum=INT_MIN, minimum=INT_MAX ;
    for (int i=0; i<10; i++){
        if (array[i]<minimum){
            minimum = array[i];
        }
        if (array[i]>maximum){
            maximum = array[i];
        }
    }
    printf("Maximum Element of the array: %d",maximum);
    printf("\nMinimum Element of the array: %d",minimum);
 }