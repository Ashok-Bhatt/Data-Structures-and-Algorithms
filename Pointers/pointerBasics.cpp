#include <iostream>
using namespace std;

int main() {

    int a = 4;
    int* b = &a;
    cout << a << endl;      // Value
    cout << *b << endl;     // Value
    cout << &a << endl;     // Address
    cout << b << endl;      // Address

    cout << typeid(a).name() << endl;   // i ---> int
    cout << typeid(b).name() << endl;   // pi ---> pointer to int

    a++;
    cout << a << endl;

    (*b)++;     // *(b)++ = *(b++) -----> prec(++)>prec(*)
    cout << *b << endl;

    char ch = 'w';
    char* ch1 = &ch;

    cout << ch << "    " << *ch1 << endl;
    
    cout << "Size of variable: " << sizeof(ch) << endl;     // 1
    cout << "Size of pointer: " <<sizeof(ch1) << endl;     // 8
}