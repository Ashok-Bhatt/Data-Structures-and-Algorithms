#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string pattern = "abba", content = "aaaabbababbab";
    string combined = pattern + "$" + content;

    int n = combined.size();
    int left = 0, right = 0;
    vector<int> zArr(n, 0);

    for (int i=1; i<n; i++){

        if (i>right){
            left = right = i;
            while (right<n && combined[right] == combined[right-left]){
                right++;
            }
            zArr[i] = right-left;
            right--;
        } else {
            int k = i-left;
            if (zArr[k] < right-i+1){
                zArr[i] = zArr[k];
            } else {
                left = i;
                while (right<n && combined[right] == combined[right-left]){
                    right++;
                }
                zArr[i] = right-left;
                right--;
            }
        }
    }

    for (int i=0; i<n; i++){
        cout << combined[i] << " ";
    }
    cout << endl;

    for (int i=0; i<n; i++){
        cout << zArr[i] << " ";
    }
}