#include <iostream>
using namespace std;

int noOfPrimes(int n){

    int count = 0;
    
    for (int i=2; i<n; i++){     
        int flag = 1;
        for (int j=2; j<i; j++){
            if (i%j==0){
                flag = 0;
                break;
            }
        }
        if (flag)
            count++;     
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