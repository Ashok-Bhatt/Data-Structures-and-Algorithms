#include<map>
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

void TwoPair(int arr[], int n, int key){
    
    // unordered_map<int, int> mapping;
    // cout << "\nAll two pair sums:\n";

    // for (int i = 0; i < n; i++) {
    //     int complement = key - arr[i];
    //     if (mapping.find(complement) != mapping.end()) {
    //         std::cout << i << " " << mapping[complement] << std::endl;
    //     }
    //     mapping[arr[i]] = i;
    // }

    
    vector<int> ans;
    map<int, vector<int>> mapping;

    cout << "\nAll two pair sums:\n";
    
    for (int i=0; i<n; i++){
        if (arr[i]<=key){
            if (mapping[key - arr[i]].size()){
                for (int j=0; j<mapping[key-arr[i]].size(); j++){
                    cout << i << " " << mapping[key-arr[i]][j] << endl;
                }
            }
            mapping[arr[i]].push_back(i); 
        }
    }
}

int main() {

    int array1[10] = {2,2,2,5,1,7,3,8,1,2};
    int key = 4;
    TwoPair(array1, 10, key);
}