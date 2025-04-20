#include <iostream>
using namespace std;

int main(){

    int arr[5] = {1,2,3,4,5};
    cout << "Address of first array elements: " << arr << endl;
    cout << "Address of first array elements: " << &arr[0] << endl;
    cout << "Address of first array elements: " << &arr << endl;

    cout << "Value at first array element: " << arr[0] << endl;
    cout << "Value at first array element: " << 0[arr] << endl;
    cout << "Value at first array element: " << *arr << endl;

    cout << "Value at second array element: " << *(arr+1) << endl;

    cout << *arr+1 << endl;

    // arr[i] --------> *(arr+i)

}