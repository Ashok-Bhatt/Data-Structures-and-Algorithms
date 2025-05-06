#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isRotated(int arr[], int n){
    int count = 0;
    for (int i=0; i<n; i++){
        if (arr[i]>arr[(i+1)%n]){
            count++;
        }
    }

    if (count==0 || count==1)
        return 1;
    return 0;
}

int main() {

    int arr1[10] = {2,3,4,5,6,7,8,9,10,4};

    // Problem 02: Check if the array is sorted and rotated
    bool isRotation = isRotated(arr1, 10);
    if (isRotation){
        cout << endl << "Rotated and Sorted" << endl;
    }
    else{
        cout << endl << "Not Rotated or Sorted" << endl;
    }
    
}