#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter n: ";
    cin >> n;

    for (int i=1; i<=2*n-1; i++){
        for (int j=1; j<=2*n-1; j++){
            cout << min(min(i,j), min(2*n-i, 2*n-j)) << " ";
        }
        cout << endl;
    }
}