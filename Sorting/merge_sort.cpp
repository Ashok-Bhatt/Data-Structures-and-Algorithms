#include <iostream>
#include <algorithm>
using namespace std;

void print(int arr[], int length){
    for (int i=0; i<length; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int s, int e, int m){
    
    int* newArray = new int[e-s+1];
    int i=s, j=m+1, newIndex=0;

    while (i<=m && j<=e){
        if (arr[i]<=arr[j])
            newArray[newIndex++] = arr[i++];
        else
            newArray[newIndex++] = arr[j++];
    }

    while (i<=m){
        newArray[newIndex++] = arr[i++];
    }

    while (j<=e){
        newArray[newIndex++] = arr[j++];
    }

    for (int index=0; index<=e-s; index++){
        arr[s+index] = newArray[index];
    }

    delete[] newArray;
    
}

void mergeSort(int arr[], int s, int e){

    if (s>=e)
        return;

    int mid = s + (e-s)/2;
    
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);

    merge(arr, s, e, mid);
    return;
    
}

int main() {

    int arr[15] = {5,2,-3,5,-1,0,0,6,-45,0,38,9,38,25,738};
    int length = sizeof(arr)/sizeof(arr[0]);

    cout << "\nArray before Sorting:" << endl;
    print(arr, length);
    
    mergeSort(arr,0,length-1);

    cout << "\nArray before Sorting:" << endl;
    print(arr, length);

    return 0;
    
}