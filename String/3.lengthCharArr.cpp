#include <iostream>
using namespace std;

int findLength(char arr[]){
    int i = 0;
    while (arr[i] != '\0'){
        i++;
    }
    return i;
}

int main(){

    char name[10] = {'A','s','h','o','k','a'};
    cout << findLength(name) << endl;

}