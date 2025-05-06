#include <iostream>
using namespace std;

int binarySearch(int arr[], int index1, int index2, int key){
    
    if (index1>index2){
        return -1;
    }
    
    int mid = index1 + (index2-index1)/2;
    
    if (arr[mid]==key){
        return mid;
    }
    else if (arr[mid] < key){
        return binarySearch(arr, mid+1, index2, key);
    }
    else{
        return binarySearch(arr, index1, mid-1, key);
    }
    
}

int main() {

    int array[5] = {12, 45, 60, 112, 300};
    int index = binarySearch(array, 0, 4, 6000);
    cout << index << endl;
    
}