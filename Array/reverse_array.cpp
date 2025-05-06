#include <iostream>
using namespace std;

void print(int arr[], int n){
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

void reverse(int arr[], int start, int end){
    while (start<end){
        swap(arr[start++],arr[end--]);
    }
}

int main() {

  // Problem 01: Reverse an array
    int array[10]={2,4,2,5,7,10,12,3,0,3};
    
    printf("Array before reversing: ");
    print(array, 10);
    reverse(array, 0, 9);
    printf("\nArray after reversing: ");
    print(array, 10);

  // Problem 02: Reverese the array after specified position
    int array1[10]={2,4,2,5,7,10,12,3,0,3};
    int position = 2;
    
    printf("\n\nArray before reversing: ");
    print(array1, 10);
    reverse(array1, position, 9);
    printf("\nArray after reversing: ");
    print(array1, 10);
    
}