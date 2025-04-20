#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    string input = "my name is Ashok and I can do this the whole day.";
    
    cout << "String before reversing: " << input << endl;

    int i=0;
    while (input[i]!='\0'){

        int j=i;
        while (input[j]!='\0' && input[j]!=' '){
            j++;
        }

        int k=j-1;
        while (i<k){
            swap(input[i++],input[k--]);
        }

        i= j+1;

    }

    cout << "String after reversing: " << input << endl; 

    return 0;

}