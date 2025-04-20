#include <iostream>
#include <queue>
using namespace std;

int main () {

    int arr[10] = {3,6,-2,0,-5,-3,-5,5,0,34};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    vector<int> ans;
    queue<int> window;

    // Creating first window
    for (int i=0; i<k; i++){
        if (arr[i]<0){
            window.push(i);
        }
    }

    if (!window.empty()){
        ans.push_back(window.front());
    }
    else{
        ans.push_back(-1);
    }

    // Processing remaining windows
    for (int i=k; i<n; i++){

        // Pushing the new possible element into window
        if (arr[i]<0){
            window.push(i);
        }

        // Popping the possible negative front
        if (!window.empty() && (i-window.front())>=k){
            window.pop();
        }

        if (window.empty()){
            ans.push_back(-1);
        }
        else{
            ans.push_back(window.front());
        }

    }

    cout << "The first negative number of each window: " << endl;
    for (int i:ans){
        if (i!=-1){
            cout << arr[i] << " ";
        }
        else{
            cout << 0 << " ";
        }
    }
    cout << endl;

}