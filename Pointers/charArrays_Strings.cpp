#include <iostream>
using namespace std;

int main(){

    char a = 's';
    cout << a << endl;

    char* a1 = &a;
    cout << a1 << endl;

    char ch[6] = {'A','s','h','o','k','\0'};

    cout << ch << endl;
    cout << ch+2 << endl;

    // Temporary memory is created and "Abcde" is copied to it and then assigned to b
    char b[6] = "Abcde";
    cout << b << endl;

    // Temporary memory is created and the first block is pointed to b1
    // char* b1 = "Abcde";     // Risky
    // cout << b1 << endl;
}