#include <iostream>
#include <map>
using namespace std;

int main() {

    map<int, string> numbers;

    // Method-I: 
    numbers[1] = "One";
    numbers[3] = "Three";
    numbers[0] = "Zero";

    // Method-II: 
    numbers.insert({8,"Eight"});

    cout << "Key-Value Pair before erasing:" << endl;
    for (auto elements:numbers){
        cout << elements.first << " ---> " << elements.second << endl;
    }
    cout << endl;

    numbers.erase(3);
    cout << "Key-Value Pair after erasing:" << endl;
    for (auto elements:numbers){
        cout << elements.first << " ---> " << elements.second << endl;
    }
    cout << endl;

    cout << "Is 8 Present:" << numbers.count(13) << endl;

    auto itr = numbers.find(1);
    // map<int,string>::iterator itr = numbers.find(1);

    for (auto it=itr; it!=numbers.end(); it++){
        cout << (*it).first << " ---> " << (*it).second << endl;
    }
}