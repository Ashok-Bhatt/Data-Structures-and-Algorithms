#include <iostream>
using namespace std;

int linearSearch(int arr[], int index, int size, int key){
    if (index==size){
        return -1;
    }
    else if (arr[index] == key){
        return index;
    }
    else{
        return linearSearch(arr, index+1, size, key);
    }
}

int main() {

    int array[5] = {12, 45, 60, 112, 300};
    int index = linearSearch(array, 0, 5, 939);
    cout << index << endl;
}