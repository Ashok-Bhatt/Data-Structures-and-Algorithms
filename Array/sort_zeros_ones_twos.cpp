#include <iostream>
using namespace std;

void SortZeroOneTwo(int arr[], int n){
    
    int i=0, j=n-1;
    while (i<j){
        while (arr[i]==0){
            i++;
        }
        while (arr[j]!=0){
            j--;
        }
        if (i<j){
            swap(arr[i],arr[j]);
        }
    }

    j = n-1;
    while (i<j){
        while (arr[i]==1){
            i++;
        }
        while (arr[j]==2){
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
    
    int arr1[10] = {0,1,1,2,2,1,0,2,0,1};
    cout << "\n\nArray before sorting: ";
    print(arr1,10);
    SortZeroOneTwo(arr1,10);
    cout << "\nArray after sorting: ";
    print(arr1,10);

    return 0;
}