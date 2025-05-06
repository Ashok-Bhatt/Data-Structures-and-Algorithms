#include <stdio.h>

int findPivot(int arr[], int s, int e){
    int mid;
    while (s<e){
        mid = s + (e-s)/2;
        if (arr[mid]>=arr[0])
            s = mid+1;
        else
            e = mid;
    }
    return e;
}

int findUpperPivot(int arr[], int s, int e){
    int mid;
    while (s<e){
        mid = s + (e-s)/2;
        if (arr[0]<arr[e])
            e = mid;
        else
            s = mid+1;
    }
    return e;
}

int binarySearch(int arr[], int s, int e, int key){
    int mid;
    while (s<=e){
        mid = s+ (e-s)/2;
        if (arr[mid]==key)
            return mid;
        else if (arr[mid]<key)
            s = mid+1;
        else
            e = mid-1;
    }
    return -1;
}

int main(void) {

    // Find pivot element in rotated array
    int arr[9] = {6,8,9,12,1,1,3,4,5};
    int length = sizeof(arr)/sizeof(4);
    
    int index = findPivot(arr, 0, length-1);
    printf("Pivot Element: %d",arr[index]);

    int index2 = findUpperPivot(arr, 0, length-1);
    printf("\nUpper Pivot Element: %d",arr[index2]);

    // Find the element in sorted and rotated array
    int key = 9, elementIndex;
    if (key >= arr[0])
        elementIndex = binarySearch(arr, 0, index-1, key);
    else
        elementIndex = binarySearch(arr, index, length, key);
    printf("\nIndex of %d is %d.",key,elementIndex);
    
    return 0;
}