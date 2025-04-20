#include <iostream>
using namespace std;

int power(int a, int b){
    if (b==1)
        return a;
    else if (b&1)
        return a*power(a*a , b/2);
    else
        return power(a*a, b/2);
}

int powerMod(int a, int b, int n){

    if (b==1)
        return a%n;
    else if (b&1)
        return (a * power((a*a)%n, b/2))%n;
    else
        return power((a*a)%n , b/2);
}

int main(){

    int a,b;
    cout << "Enter a and b separated by space: ";
    cin >> a >> b;

    int ans1 = power(a,b);
    cout <<  a << "^" << b << " = " << ans1 << endl;;

    int n;
    cout << "Enter a, b and n separated by space: ";
    cin >> a >> b >> n;

    int ans2 = powerMod(a, b, n);
    cout <<  a << "^" << b << " = " << ans2;

}