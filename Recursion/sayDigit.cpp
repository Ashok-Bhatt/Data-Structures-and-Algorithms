#include <iostream>
using namespace std;

void sayDigits(int n){
    if (n==0){
        cout << endl;
        return;
    }

    char mapping[10][6] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    sayDigits(n/10);
    cout << mapping[n%10] << " ";
}

int main() {

    int num;
    cout << "Enter the number: ";
    cin >> num;
    
    if (num==0){
        cout << endl << "Zero";
    }
    else{
        sayDigits(num);
    }
    
}