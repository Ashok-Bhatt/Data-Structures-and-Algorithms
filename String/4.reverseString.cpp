#include <iostream>
using namespace std;

// pass by reference
void reverse(string &x){

    int i=0, j=x.length()-1;

    while (i<j){
        swap(x[i++],x[j--]);
    }
}

int main(){

    string x = "Nasikabadrachusiyadrensis";

    cout << "String before reversing: " << x << endl;
    reverse(x);
    cout << "String after reversing: " << x << endl;

}