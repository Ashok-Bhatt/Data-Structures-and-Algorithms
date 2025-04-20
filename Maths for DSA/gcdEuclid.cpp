#include <iostream>
using namespace std;

int findHCF(int num1, int num2){
    if (num2==0){
        return num1;
    }
    return findHCF(num2, num1%num2);
}

int main(){

    int num1, num2;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    int hcf = findHCF(num1,num2);
    int lcm = (num1*num2)/hcf;

    cout << "hcf = " << hcf << endl;
    cout << "lcm = " << lcm << endl;

}