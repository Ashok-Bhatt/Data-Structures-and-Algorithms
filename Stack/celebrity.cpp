#include <iostream>
#include <stack>
using namespace std;

int main(){
    
    // If arr[i][j] == 1 -------> i knows j

    int arr[3][3] = {{0,1,0},
                    {0,0,0},
                    {0,1,0}};
    
    int person = sizeof(arr[0])/sizeof(arr[0][0]);


    // Brute Force :

    int celebrity = -1;
    for (int i=0; i<person; i++){

        int knowCount = 0;
        int knownCount = 0;
        for (int j=0; j<person; j++){
            knowCount = knowCount + arr[i][j];
            knownCount = knownCount + arr[j][i];
        }

        if (knowCount == 0 && knownCount == person-1){
            celebrity = i;
            break;
        }
    }

    cout << "By Brute Force: " << endl;
    if (celebrity != -1){
        cout << "Person " << celebrity << " is celebrity." << endl << endl;
    }
    else{
        cout << "Celebrity not found." << endl;
    }


    // Optimised Solution using stack:

    stack<int> contender;

    for (int i=0; i<person; i++){
        contender.push(i);
    }

    while (contender.size() != 1){

        int a = contender.top();
        contender.pop();
        int b = contender.top();
        contender.pop();

        if (arr[a][b] == 1){
            contender.push(b);
        }
        else if (arr[b][a] == 1){
            contender.push(a);
        }
    }

    int know = 0, known = 0;
    int lastContender = contender.top();

    for (int i=0; i<person; i++){
        if (arr[lastContender][i]){
            know++;
        }
        if (arr[i][lastContender]){
            known++;
        }
    }

    cout << "Using stack: " << endl;
    if (know==0 && known==person-1){
        cout << lastContender << " is a celebrity." << endl;
    }
    else{
        cout << "No celebrity found! " << endl;
    }

}