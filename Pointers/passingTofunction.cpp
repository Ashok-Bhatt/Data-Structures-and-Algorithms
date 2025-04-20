#include <iostream>
using namespace std;

void incrementValue(int num){
    num++;
}

void incrementValue2(int* &num){
    (*num)++;
}

void incrementPointer(int* num){
    // Pointer passed
    num++;
}

void incrementPointer2(int* &num){
    // Address of pointer is passed
    num++;
}

int getSum(int* arr, int n){
    int sum = 0;
    for (int i=0; i<n; i++){
        cout << "i: " << i << "     arr[i]: " << arr[i] << endl;
        sum = sum + arr[i];
    }
    return sum;
}

int main(){

    int num = 1;
    int* ptr = &num;

    cout << num << endl;
    incrementValue(num);
    cout << num << endl;
    incrementValue2(ptr);
    cout << num << endl;

    cout << ptr << endl;
    incrementPointer(ptr);
    cout << ptr << endl;
    incrementPointer2(ptr);
    cout << ptr << endl;

    int arr[7] = {1,2,3,4,5,6,7};
    cout << getSum(arr+2,7) << endl;

}