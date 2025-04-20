#include <iostream>
#include <algorithm>
using namespace std;

int findPivot(int arr[], int s, int e){

    int count = 0;
    int pivot = s;
    
    for (int i=s+1; i<=e; i++){
        if (arr[i]<arr[pivot])
            count++;
    }

    swap(arr[pivot], arr[pivot+count]);
    pivot = pivot+count;

    int i=s, j=e;
    while (i<pivot && j>pivot){

        while (arr[i]<arr[pivot])
            i++;
        while (arr[j]>=arr[pivot])
            j--;
        if (i<pivot && j>pivot)
            swap(arr[i],arr[j]);
    }

    return pivot;
}

void quickSort(int arr[], int s, int e){

    if (s>=e){
        return;
    }

    int pivot = findPivot(arr, s, e);
    
    quickSort(arr, pivot+1, e);
    quickSort(arr, s, pivot-1);    
    
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
    
    quickSort(arr,0,length-1);

    cout << "\nArray before Sorting:" << endl;
    print(arr, length);

    return 0;
    
}