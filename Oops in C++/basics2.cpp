
// Semicolon is provided at the end of the class definition in C++ because the compiler checks if the user has created an instance of the class after it's definition just like in structures and unions.

#include <iostream>
using namespace std;

class Person{

public:
    string name;
    int age;

    Person(){
        cout << "Person Created with non-parameterized constructor" << endl;
    }

    Person(string n, int a){
        name = n;
        age = a;
        cout << "Person created with parameterized constructor" << endl;
    }
}p1, p2("irfan", 21);

int main() {
    p1.name = "ashok";
    cout << p1.name << " " << p1.age << endl;
}