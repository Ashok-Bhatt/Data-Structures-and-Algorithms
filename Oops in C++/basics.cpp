
//NOTE: The order of destructor call for local variable is reverse of the order of their creation

#include <iostream>
using namespace std;

class Student {

public:
    string name;
    int age;

    // unparameterized constructor for Student class
    Student () {
        cout << "New student created. " << endl;
    }

    // parameterized constructor for Student class
    Student (string n, int a){
        name = n;
        age = a;
    }

    // destructor for Student class
    ~Student() {
        cout << "Object with name " << name << " deleted." << endl;
    }
    
    void printName(){
        cout << "name: " << name << endl;
    }

    void printAge();
};

// we are defining the method of Student class outside the class using :: (scope resolution operator)
void Student::printAge(){
    cout << "age: " << age << endl;
}

int main(){

    Student s1;     // will trigger the unparameterized constructor
    s1.name = "ashok";
    s1.age = 20;

    Student s2("irfan", 21);    // will trigger the parameterized constructor

    s1.printName();
    s1.printAge();
    s2.printName();
    s2.printAge();

    return 0;
}