#include <iostream>
using namespace std;

int main(){

    int a = 100;
    int *a1 = &a;

    cout << a1 << "     " << *(a1) << endl;
    cout << a1+1 << "     " << *(a1+1) << endl;  // address(a+1) == address(a) + 4 <--- int data type

}