#include <iostream>
#include <string.h>
using namespace std;

void print(char arr[], int size){

    for (int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

    // Raises Error:
    // char arr1[5] = {'a','b','c','d','e','f'};

    char arr1[5] = {'a','b','m','d','e'};
    print(arr1, 5);

    char arr2[5] = {'a','c','m','d','e'};
    print(arr2, 5);

    cout << "Length of character array: " << strlen(arr1) << endl;
    cout << "Comparing arr1 and arr2: " << strcmp(arr1,arr2) << endl;

    strcpy(arr1, arr2);

    print(arr1, 5);
    print(arr2, 5);

}