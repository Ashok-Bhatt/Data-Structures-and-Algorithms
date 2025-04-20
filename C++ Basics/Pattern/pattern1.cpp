#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter N: ";
    cin >> n;

    for (int i=0; i<n; i++){
        
        // printing spaces
        for (int j=1; j<n-i; j++){
            cout << " ";
        }

        // printing characters of left side + center
        for (int j=0; j<=i; j++){
            cout << char('A' + j);
        }

        // printing right side
        for (int j=i-1; j>=0; j--){
            cout << char('A' + j);
        }

        // printing space for new line for new row
        cout << "\n";
    }
}