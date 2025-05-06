#include <iostream>
using namespace std;

void changeArray(int arr[], int n){

    int nonZero = 0;
    while (nonZero<n){
        while (arr[nonZero]==0){
            nonZero++;
        }
        if (nonZero<n){
            for (int i=0; i<n; i++){
                if (arr[i]==0){
                    swap(arr[i],arr[nonZero]);
                    break;
                }
            }   
        }
    }
    
}

void print(int array[], int n){
    for (int i=0; i<n; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {

    // Problem 01: Move zeros to right side of an array:
    int arr1[10] = {0,2,4,5,0,4,5,0,0,7};

    cout << "Array (Before): " << endl;
    print(arr1,10);

    changeArray(arr1,10);
    cout << "Array (After): " << endl;
    print(arr1,10);
    
}