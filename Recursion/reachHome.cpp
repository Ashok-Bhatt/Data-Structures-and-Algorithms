#include <iostream>
using namespace std;

void ReachHome(int num){
    if (num==0){
        cout << endl << "Reached Home" << endl << endl;
        return;
    }
    cout << endl << num << " Steps away from Home";
    ReachHome(num-1);
    
}

int main() {

    int num;
    cout << "Enter the number:";
    cin >> num;

    ReachHome(num);
    
}