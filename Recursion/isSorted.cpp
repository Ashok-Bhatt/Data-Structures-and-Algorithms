#include <iostream>
using namespace std;

int IsSorted(int arr[], int index, int size){
    if (index==size-1){
        return 1;
    }
    else if (arr[index] < arr[index+1]){
        return IsSorted(arr, index+1, size);
    }
    else{
        return 0;
    }
}

int main() {

    int array[5] = {12, 45, 60, 112, 300};
    int ans = IsSorted(array, 0, 5);
    
    if (ans){
        cout << "Array is sorted." << endl;
    }
    else{
        cout << "Array is not sorted." << endl;
    }
}