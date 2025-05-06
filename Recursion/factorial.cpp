#include <iostream>
using namespace std;

int factorial(int num){
    if (num==1)
        return 1;
    return num*factorial(num-1);
}

int main() {

    int num;
    cout << "Enter the number:";
    cin >> num;

    int fact = factorial(num);
    cout << endl << "Factorial: " << fact << endl;
    
}