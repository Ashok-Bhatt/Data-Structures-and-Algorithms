#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> vec;
    cout << endl << "Capacity: " << vec.capacity() << "    Size: " << vec.size() << endl;

    vec.push_back(46);
    cout << endl << "Capacity: " << vec.capacity() << "    Size: " << vec.size() << endl;

    vec.push_back(-4);
    cout << endl << "Capacity: " << vec.capacity() << "    Size: " << vec.size() << endl;
    
    vec.push_back(2);
    vec.push_back(9);
    cout << endl << "Capacity: " << vec.capacity() << "    Size: " << vec.size() << endl;
    cout << "First Element: " << vec.front() << "    Last element: " << vec.back() << endl;

    vec.pop_back();
    cout << endl << "Capacity: " << vec.capacity() << "    Size: " << vec.size() << endl;
    cout << "First Element: " << vec.front() << "    Last element: " << vec.back() << endl;

    // Copying one vector into another one
    vector<int> vec2(vec);
    
    vec.clear();
    cout << endl << "Capacity: " << vec.capacity() << "    Size: " << vec.size() << endl;

    // Traversing the whole vector
    cout << endl << endl << "Vector Traversal" << endl;
    for (int i:vec2){
        cout << i << " ";
    }

    // Initializing vector
    vector<int> vec3(3,100);
    cout << endl << endl << "Traversing the vector of size 3 of all elements 100" << endl;
    for (int i:vec3){
        cout << i << " ";
    }
    
}