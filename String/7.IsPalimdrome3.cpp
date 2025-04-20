// Program to check whether the string is plaimdrome or not by removing the non-alphanumeric characters and converting the characters to lowercase

#include <iostream>
using namespace std;

char lowercase(char x){
    if ((x>'A') || (x<'Z'))
        return x-'A'+'a';
    else
        return x;
}

bool IsPalimdrome(string x){

    int i=0, j=x.length()-1;
    while (i<j){

        while (!((lowercase(x[i])>='a' && lowercase(x[i])<='z') || (x[i]>='0' && x[i]<='9')))
            i++;

        while (!((lowercase(x[j])>='a' && lowercase(x[j])<='z') || (x[j]>='0' && x[j]<='9')))
            j--;

        if ((x[i] != x[j])){
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

    string x = "Ja1h1aj";

    bool ans = IsPalimdrome(x);
    
    if (ans)
        cout << "Given string is palimdrome." << endl;
    else
        cout << "Given string is not palimdrome." << endl;

}