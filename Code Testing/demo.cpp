#include<bits/stdc++.h>
using namespace std;
// use (SHIFT + CTRL + B) to run the program

float findRoot(int n){
        
    float s = 1, e = n, mid;
    while (s<=e){
        mid = int( (s + int(e-s)/2) * 1000) / 1000;
        cout << mid << " ";
        if (mid == float(n)){
            return mid;
        } else if (mid < float(n)){
            s = mid + 0.001;
        } else {
            e = mid - 0.001;
        }
    }
    
    return mid;
}

vector<int> jugglerSequence(int n) {
    
    vector<int> ans = {n};
    int size = 1;
    
    while (true){
        
        if (ans[size-1] == 1){
            break;
        }
        
        float root = findRoot(ans[size-1]);
        if (ans[size-1] % 2 == 0){
            ans.push_back(int(root));
        } else {
            ans.push_back(int(ans[size-1] * root));
        }
        size++;
    }
    
    return ans;
}

void main(){

    int n;
    cin >> n;
    // float ans = findRoot(n);
    cout << n*10;
}