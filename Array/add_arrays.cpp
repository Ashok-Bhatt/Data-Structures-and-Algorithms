#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<int> vec){
    for (int i:vec){
        cout << i << " ";
    }
    cout << endl;
}

vector<int> sumOfArray(int arr1[], int m, int arr2[], int n){

    vector<int> ans;
    int i=m-1, j=n-1;
    int carry = 0;

    while (i>=0 && j>=0){
        int sum = arr1[i] + arr2[j] + carry;
        ans.push_back(sum%10);
        carry = sum/10;
        i--;
        j--;
    }

    while (i>=0){
        int sum = arr1[i] + carry;
        ans.push_back(sum%10);
        carry = sum/10;
        i--;
    }

    while (j>=0){
        int sum = arr2[j] + carry;
        ans.push_back(sum%10);
        carry = sum/10;
        j--;
    }

    while (carry){
        ans.push_back(carry%10);
        carry = carry/10;
    }

    reverse(ans.begin(),ans.end());
    return ans;   
}

int main() {

    int arr1[10] = {2,3,4,5,6,7,8,9,10,4};

    // Problem 03: Add two arrays:
    int array1[4] = {1,2,3,4};
    int array2[4] = {9,8,7,6};
    int m = sizeof(array1)/4;
    int n = sizeof(array2)/4;

    vector<int> ans = sumOfArray(array1,m,array2,n);
    cout << endl;
    printVector(ans);
    
}