#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void push(vector<int> &arr, vector<int> &top, vector<int> &next, int* freespace, int stackNo, int value){

    if (*freespace == -1){
        cout << "Stack Overflow! " << endl;
        return;
    }

    int index = *freespace;
    *freespace = next[index];
    next[index] = top[stackNo-1];
    top[stackNo-1] = index;
    arr[index] = value;

}

void pop(vector<int> &arr, vector<int> &top, vector<int> &next, int *freespace, int stackNo){

    if (top[stackNo-1] == -1){
        cout << "Stack Underflow! " << endl;
        return;
    }

    int index = top[stackNo-1];
    top[stackNo-1] = next[index];
    next[index] = *freespace;
    *freespace = index;

    cout << "Popped Element: " << arr[index] << endl;

}

int main(){

    int n=5, k=3;

    // Initializing the array and stack
    vector<int> arr(n);
    vector<int> top(k, -1);

    // Initializing the next array
    vector<int> next(n, -1);
    for (int i=0; i<n-1; i++){
        next[i] = i+1;
    }

    int freespace = 0;

    push(arr, top, next, &freespace, 1, 5);
    push(arr, top, next, &freespace, 2, 50);
    push(arr, top, next, &freespace, 3, 35);
    push(arr, top, next, &freespace, 3, 52);
    push(arr, top, next, &freespace, 1, 3);
    pop(arr, top, next, &freespace, 3);
    pop(arr, top, next, &freespace, 3);
    pop(arr, top, next, &freespace, 3);

}