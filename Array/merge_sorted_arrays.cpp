#include <iostream>
#include <vector>;
using namespace std;

void merge(int arr1[], int m, int arr2[], int n){

    vector<int> ans;
    int first=0, second=0;

    while (first<m && second<n){
        if (arr1[first]<arr2[second]){
            ans.push_back(arr1[first]);
            first++;
        }
        else{
            ans.push_back(arr2[second]);
            second++;
        }
    }

    while (first<m){
        ans.push_back(arr1[first]);
        first++;
    }

    while (second<n){
        ans.push_back(arr2[second]);
        second++;
    }

    for (int i:ans){
        cout << i << " ";
    }
    cout << endl;
}

void printArray(int arr[], int n){
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;   
}

int main() {

    // Problem 1: Merge two sorted arrays
    int array1[10] = {2,4,5,6,7,10,21,34,56,67};
    int array2[8] = {2,3,4,5,10,14,20,40};

    cout << "Before Merging:" << endl;
    printArray(array1, 10);
    printArray(array2, 8);

    cout << endl << "After Merging:" << endl;
    merge(array1, 10, array2, 8);
}