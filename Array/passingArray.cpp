#include <iostream>
using namespace std;

void print(int arr[], int size){
    for (int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// change1 and change2 are same

void change1(int arr[]){
    arr[0] = 100;
}

void change2(int *arr){
    arr[0] = 100;
}

int main(){

    int arr1[] = {1,2,3,4,5};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);

    int arr2[] = {6,7,8,9,10};
    int size2 = sizeof(arr2)/sizeof(arr2[0]);

    cout << "Array before changing: " << endl;
    print(arr1,size1);

    cout << "Array after changing (pass by value): " << endl;
    change1(arr1);
    print(arr1,size1);

    cout << "Array after changing (pass by pointer): " << endl;
    change2(arr1);
    print(arr1,size1);

}