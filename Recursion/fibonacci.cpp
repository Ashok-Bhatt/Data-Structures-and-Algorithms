#include <iostream>
using namespace std;

int fibonacci(int num){
    if (num==0 or num==1){
        return num;
    }
    else{
        return fibonacci(num-1) + fibonacci(num-2);
    }
}

int main() {

    int num;
    cout << "Enter the number:";
    cin >> num;

    cout << "Fibonacci Term:" << endl;
    cout << fibonacci(num) << endl;
    
}