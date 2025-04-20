#include <iostream>
using namespace std;

int main(){

    int a = 100;
    int *a1 = &a;
    int* b = a1;

    cout << a1 << "   " << b << endl;
}