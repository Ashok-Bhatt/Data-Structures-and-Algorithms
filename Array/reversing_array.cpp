#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int arr[], int n){

    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
}

int main() {

    int arr[] = {1,2,3,4,5};
    int n = 5, d = 2;

    d = d % n;

    printArray(arr, n);
    reverse(arr, arr+d);      // why it's not giving      2 1 3 4 5
    printArray(arr, n);
    reverse(arr+d, arr+n);    // why it's not giving      2 1 5 4 3
    printArray(arr, n);
    reverse(arr, arr+n);      // why it's not giving      3 4 5 1 2
    printArray(arr, n);
}