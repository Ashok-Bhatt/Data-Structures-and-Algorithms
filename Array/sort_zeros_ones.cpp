#include <iostream>
using namespace std;

void SortZeroOne(int arr[], int n){
    int i = 0, j=n-1;

    while (i<j){
        while (arr[i]==0){
            i++;
        }
        while (arr[j]==1){
            j--;
        }
        if (i<j){
            swap(arr[i],arr[j]);
        }
    }
}

void print(int arr[], int n){
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

int main() {

    int arr[10] = {0,1,1,0,0,1,1,0,0,1};
    cout << "Array before sorting: ";
    print(arr,10);
    SortZeroOne(arr,10);
    cout << "\nArray after sorting: ";
    print(arr,10);

    return 0;
}