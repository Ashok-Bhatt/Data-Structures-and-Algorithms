#include <iostream>
using namespace std;

void DecCounting(int num){
    if (num==1){
        cout << 1 << " ";
        return;
    }
    cout << num << " ";
    return DecCounting(num-1);
}

int main() {

    int num;
    cout << "Enter the number:";
    cin >> num;

    cout << endl << "Decreasing Count:" << endl;
    DecCounting(num);
    
}