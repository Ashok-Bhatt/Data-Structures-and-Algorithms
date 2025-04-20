#include <iostream>
using namespace std;

int main(){

    int num = 5;
    int *a = &num;
    int* b = &num;

    cout << "a: " << a << "     " << *a << endl;    // Same address
    cout << "b: " << b << "     " << *b << endl;    // Same address

    
}