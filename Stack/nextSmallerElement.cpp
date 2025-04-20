#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void print(vector<int> vec){

    for (int i:vec){
        cout << i << " ";
    }
    cout << endl << endl;

}

int main(){

    vector<int> input;
    input.push_back(4);
    input.push_back(7);
    input.push_back(5);
    input.push_back(6);
    input.push_back(10);

    int size = input.size();

    // Brute Force:
    // T.C. : O(n^2)        S.C. : O(n)

    vector<int> output1(size, -1);

    for (int i=0; i<size; i++){
        for (int j=i+1; j<size; j++){
            if (input[j] < input[i]){
                output1[i] = input[j];
                break;
            }
        }
    }

    cout << "Output by brute force: " << endl;
    print(output1);
    
    // Using stack:
    // T.C.: O(n^2) {but more optimised for best case scenerios---> O(n)}        S.C.: O(n)

    vector<int> output2(size,-1);

    stack<int> intermediate;
    intermediate.push(-1);

    for (int i=size-1; i>=0; i--){

        while (intermediate.top()>=input[i]){
            intermediate.pop();
        }

        output2[i] = intermediate.top();
        intermediate.push(input[i]);
    }

    cout << "Output using stack: " << endl;
    print(output2);


    // By Ashok Bhatt Approach:
    // T.C.: O(n)       S.C.: O(n)

    vector<int> output3(5,-1);
    int smallest = input[size-1];

    for (int i=size-2; i>=0; i--){
        if (input[i] > smallest){
            output3[i] = smallest;
        }
        else{
            smallest = input[i];
        }
    }

    cout << "Output using Ashok Bhatt Approach: " << endl;
    print(output3);

}