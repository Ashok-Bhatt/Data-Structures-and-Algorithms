#include <iostream>
using namespace std;

void IncCounting(int num){
    if (num==1){
        cout << 1 << " ";
        return;
    }
    IncCounting(num-1);
    cout << num << " ";
    return;
}

int main() {

    int num;
    cout << "Enter the number:";
    cin >> num;

    cout << endl << "Increasing Count:" << endl;
    IncCounting(num);
    
}