#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(int arr1[], int n){
    for (int i=0; i<n; i++){
        cout << arr1[i] << " ";
    }
    cout << endl;
}

void printVector(vector<int> vec){
    for (int i:vec){
        cout << i << " ";
    }
    cout << endl;
}

vector<int> leftRotate(int arr[], int n, int order){

    vector<int> ans(n,0);
    for (int i=0; i<n; i++){
        ans[(i+order)%n] = arr[i];
    }

    return ans;
}

vector<int> rightRotate(int arr[], int n, int order){

    vector<int> ans(n,0);
    for (int i=0; i<n; i++){
        int index = (i-order)%n;
        if (index<0){
            index = index + n;
        }
        ans[index%n] = arr[i];
    }

    return ans;
}

int main() {

    int arr1[10] = {2,3,4,5,6,7,8,9,10,4};

    // Problem 01: Rotate the array by k places
    cout << "Array before rotation: " <<  endl;
    print(arr1,10);

    vector<int> ans1 = leftRotate(arr1,10,1);
    cout << "Array after left rotation: " <<  endl;
    printVector(ans1);

    vector<int> ans2 = rightRotate(arr1,10,3);
    cout << "Array after right rotation: " <<  endl;
    printVector(ans2);
    
}