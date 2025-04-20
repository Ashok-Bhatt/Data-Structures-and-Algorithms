#include <bits/stdc++.h>
using namespace std;

vector<int> findPrimes(int right){

    vector<int> ans;
    vector<int> arr(10000,1);
    arr[0] = arr[1] = 0;

    for (int i=2; i*i<=right; i++){
        if (arr[i]==1){
            ans.push_back(i);
            for (int j=2*i; j<10000; j=j+i){
                arr[j] = 0;
            }
        }
    }

    return ans;   
}

void printVector(vector<int> arr){
    for (int element:arr){
        cout << element << " ";
    }
    cout << endl;
}

int main() {

    int left, right;
    cout << "Enter starting number: ";
    cin >> left;
    cout << "Enter ending number: ";
    cin >> right;

    // Extracting all the primes upto the range of square root of right
    vector<int> primes = findPrimes(right);
    // Creating a dummy array that will contain the the values from left to right
    vector<int> range(right-left+1, 1);

    // Using each prime for marking
    for (int element:primes){
        
        // Finding the first index from which marking will be started
        int starting_index = (left/element)*element;
        if (starting_index!=left){
            starting_index = starting_index + element;
        }
        int index = max(element*element, starting_index) - left;

        for (int i=index; i<=right-left; i=i+element){
            range[i] = 0;
        }
    }

    vector<int> ans;
    for (int i=0; i<=right-left; i++){
        if (range[i]==1){
            ans.push_back(left+i);
        }
    }

    cout << "All primes in given range: " << endl;
    printVector(ans);
}