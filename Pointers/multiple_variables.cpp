#include <iostream>
using namespace std;

int main(){

    int a = 100;
    int *a1 = &a;
    int b = *a1;

    cout << a << "   " << b << endl;

    
    int num1 = 100;
    int* p = &num1;
    (*p)++;
    cout << num1 << endl;
}