#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr((istream_iterator<int>(cin)), istream_iterator<int>());
    for (int i=0; i<n; i++){
        cout << arr[i] << " "; 
    }
    cout << endl;
}