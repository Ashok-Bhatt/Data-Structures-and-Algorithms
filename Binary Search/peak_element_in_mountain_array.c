#include <stdio.h>

int main(void) {

    // Problem 01: Find the peak element in mountain array:
    int arr[10] = {1,3,5,5,6,6,8,10,10,7};
    int s =0, e = sizeof(arr)/sizeof(arr[0])-1, mid;

    while (s<e){
        mid = (s+e)/2;
        if (arr[mid]<=arr[mid+1])
            s = mid+1;
        else
            e = mid;
    }

    printf("Peak element in mountain array: %d",arr[e]);
    
return 0;
}