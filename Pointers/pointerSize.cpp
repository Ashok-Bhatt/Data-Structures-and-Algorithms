#include <iostream>
using namespace std;

int main(){

    int a = 45;
    int *a1 = &a;
    
    cout << sizeof(a) << endl;
    cout << sizeof(a1) << endl;
    cout << sizeof(&a1) << endl;
    
}