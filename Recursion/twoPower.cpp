#include <iostream>
using namespace std;

int TwoPower(int num){
    if (num==1)
        return 2;
    return 2*TwoPower(num-1);
}

int main() {

    int num;
    cout << "Enter the number:";
    cin >> num;

    int power = TwoPower(num);
    cout << endl << "TwoPower: " << power << endl;
    
}