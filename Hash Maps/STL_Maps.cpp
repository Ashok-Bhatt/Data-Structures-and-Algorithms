#include <bits/stdc++.h>
using namespace std;

int main(){
    
    unordered_map<int,int> mapping;

    // Inserting using pair
    pair<int,int> p1 = make_pair(10,3);
    mapping.insert(p1);
    pair<int,int> p2(1,3);
    mapping.insert(p2);

    // Inserting using key name
    mapping[6] = 47;

    // Updating the value for given key
    mapping[1] = 1000;
    mapping[67] = 326;
    mapping[90] = 32;

    // Accessing the mapping values using key name
    cout << mapping[10] << endl;        // Creates a key having default value
    cout << mapping.at(1) << endl;      // Gives error if key is not found

    // Getting the size of mapping
    cout << "Size of mapping: " << mapping.size() << endl;

    // Checking if mapping is empty or not
    cout << "Is key 4 present: " << mapping.count(1) << endl;

    // Removing the key value pair
    cout << "Size of mapping before deleting key-value pair for key 1: " << mapping.size() << endl;
    mapping.erase(1);
    cout << "Size of mapping after deleting key-value pair for key 1: " << mapping.size() << endl << endl;;

    // Traversing through map
    cout << "Normal Traversing: " <<endl;
    for (auto element:mapping){
        cout << "Key: " << element.first << "   Value: " << element.second << endl;
    }
    cout << endl;

    cout << "Traversing using iterator: " <<endl;
    unordered_map<int,int> :: iterator it = mapping.begin();
    while (it != mapping.end()){
        cout << "Key: " << it->first << "   Value: " << it->second << endl;
        it++;
    }
    cout << endl;
}