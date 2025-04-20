#include <iostream>
using namespace std;

int main(){

    int N;
    cout << "N: ";
    cin >> N;

    // Approach 1:
    cout << "Approach 1:" << endl;
    for (int i=0; i<N; i++){
        for (int j=0; j<=i; j++){
            cout << i*(i+1)/2 + j + 1 << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Approach 2:
    cout << "Approach 2:" << endl;
    int number = 1;
    for (int i=0; i<N; i++){
        for (int j=0; j<=i; j++){
            cout << number << " ";
            number++;
        }
        cout << endl;
    }
    cout << endl;

}