#include <iostream>
using namespace std;

bool IsPalimdrome(string x){

    int i=0, j=x.length()-1;

    while (i<j){
        if (x[i] != x[j]){
            return 0;
        }
        else{
            i++;
            j--;
        }
    }

    return 1;
}

int main(){

    string x = "jahaj";

    bool ans = IsPalimdrome(x);
    
    if (ans)
        cout << "Given string is palimdrome." << endl;
    else
        cout << "Given string is not palimdrome." << endl;

}