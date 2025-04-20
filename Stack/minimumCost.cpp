#include <iostream>
#include <stack>
using namespace std;

int main(){

    string input = "}}}}{{{{";
    int size = input.size();
    
    if (size&1){
        cout << "Not possible to balance the provided set of braces." << endl;
    }
    else{

        stack<int> balance;

        // Removing all balanced braces
        for (int i=0; i<size; i++){

            int element = input[i];
            if (element == '{'){
                balance.push(element);
            }
            else{
                if (!balance.empty() && balance.top()=='{'){
                    balance.pop();
                }
                else{
                    balance.push(element);
                }
            }
        }

        // Finding the answer
        int a = 0;
        int b = 0;

        while (!balance.empty()){
            if (balance.top()=='{'){
                a++;
            }
            else{
                b++;
            }
            balance.pop();
        }

        int ans = (a+1)/2 + (b+1)/2;
        cout << "Minimum cost required to balance the set of braces: " << ans << endl;

    }

}