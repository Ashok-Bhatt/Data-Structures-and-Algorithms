#include <iostream>
#include <algorithm>
using namespace std;

void insertionSort(int arr[], int length){

    for (int i=1; i<length; i++){
        int pivot = arr[i];
        int j = i-1;
        while (arr[j]>=pivot && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = pivot;
    }
    
}

void print(int arr[], int length){
    for (int i=0; i<length; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int arr[15] = {5,2,-3,5,-1,0,0,6,-45,0,38,9,38,25,738};
    int length = sizeof(arr)/sizeof(arr[0]);

    cout << "\nArray before Sorting:" << endl;
    print(arr, length);
    
    insertionSort(arr,length);

    cout << "\nArray before Sorting:" << endl;
    print(arr, length);

    return 0;
    
}