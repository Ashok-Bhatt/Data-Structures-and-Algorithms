#include <iostream>
#include <algorithm>
using namespace std;

void selectionSort(int arr[], int length){

    for (int i=0; i<length-1; i++){
        
        int minimum = i;
        for (int j=i+1; j<length; j++){
            if (arr[j]<arr[minimum])
                minimum = j;
        }

        swap(arr[i],arr[minimum]);
        
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

    cout << "Array before Sorting:" << endl;
    print(arr, length);
    
    selectionSort(arr,length);

    cout << "\nArray before Sorting:" << endl;
    print(arr, length);

    return 0;
    
}