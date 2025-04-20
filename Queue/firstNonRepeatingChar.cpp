#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

int main(){

    string input = "ahsoka";
    unordered_map<char,int> occurance;
    queue<char> order;
    int size = input.length();

    string output;

    for (int i=0; i<size; i++){
        
        char element = input[i];
        occurance[element]++;
        order.push(element);

        while (!order.empty() && occurance[order.front()]>1){
            order.pop();
        }

        if (order.empty()){
            output.push_back('#');
        }
        else{
            output.push_back(order.front());
        }
    }

    cout << "Input String: " << input << endl;
    cout << "Output String: " << output << endl;

}