#include <iostream>
#include <vector>
using namespace std;

int noOfPrimes(int n){

    vector<int> ans(n, 1);
    ans[0] = 0;
    ans[1] = 0;

    for (int i=2; i<n; i++){
        if (ans[i]==1){
            for (int j=2*i; j<n; j=j+i){
                ans[j] = 0;
            }
        }
    }

    int count = 0;
    for (int i=0; i<n; i++){
        if (ans[i] == 1){
            count++;
        }
    }

    return count;
    
}

int main() {

    int N;
    cout << "Enter the number: ";
    cin >> N;

    int count = noOfPrimes(N);
    cout << "Total primes less than " << N << " : " << count << endl;

}