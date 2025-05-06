#include <iostream>
using namespace std;

int SumofArray(int arr[], int index, int size){
    if (index==size-1){
        return arr[index];
    }
    return arr[index] + SumofArray(arr, index+1, size);
}

int main() {

    int array[5] = {12, 45, 60, 112, 300};
    int sum = SumofArray(array, 0, 5);
    cout << sum;

}