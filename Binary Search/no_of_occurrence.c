#include <stdio.h>

int main(void) {

    // Problem 02: Find number of occurrences of the number in an array using binary search
    
    int array1[100] = {6,7,7,7,7,8,10,10,11,14,14,17,18,18};
    int key, left = -1, right = -1;
    int start = 0, end = 13, mid;

    printf("Enter the key:");
    scanf("%d",&key);

    // To get left occurrence
    int start1 = start, end1 = end;
    while (start1<=end1){
        mid = start1+(end1-start1)/2;
        if (array1[mid]==key){
            left = mid;
            end1 = mid-1;
        }
        else if (array1[mid]<key)
            start1 = mid+1;
        else
            end1 = mid-1;
    }

    // To get right occurrence
    start1 = start, end1 = end;
    while (start1<=end1){
        mid = start1+(end1-start1)/2;
        if (array1[mid]==key){
            right = mid;
            start1 = mid+1;
        }
        else if (array1[mid]<key){
            start1 = mid+1;
        }
        else{
            end1 = mid-1;
        }
    }

    int number;
    if (left==-1)
        number = 0;
    else
        number = right - left + 1;
    printf("The number of occurrences of %d is %d",key,number);

    return 0;
}