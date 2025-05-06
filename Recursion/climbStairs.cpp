#include <iostream>
using namespace std;

int ClimbStairs(int n){
    if (n==-1)
        return 0;
    else if (n==0)
        return 1;
    return ClimbStairs(n-1) + ClimbStairs(n-2);
}

int main() {

    
    int stairs;
    cout << "Enter no. of stairs: ";
    cin >> stairs;

    int climb = ClimbStairs(stairs);

    cout << endl << "No. of ways of climbing stairs:" << climb << endl;
    
}