#include <limits.h>
#include <stdio.h>

int main() {
  
     // Problem 03: Find whether an element lies in array or not
    int array[10]={2,4,2,5,7,10,12,3,0,-1}, key, index=-1;
    printf("Enter the key you want to find in an array: ");
    scanf("%d",&key);
    for (int i=0; i<10; i++){
        if (array[i]==key){
            index = i;
            break;
        }
    }
    if (index==-1){
        printf("\nThe element is not present in an array.");
    }
    else{
        printf("\nThe index of the entered key in an array is %d.",index);
    }
 }