#include <iostream>
using namespace std;

int factorial(int n){
    
    int mod = 1000000007;
    long long ans = 1;

    for (int i=2; i<=n; i++){
        ans = (ans*i)%mod;
    }

    return ans;
}

int main(){

    int n;
    cout << "Enter the number: ";
    cin >> n;

    int ans = factorial(n);
    cout << "n! = " << ans << endl;

}