# include <iostream>
using namespace std;

int main(){

    string name = "Ashok Bhatt";
    string game = "COC";

    cout << "Printing String directly: " << endl;
    cout << name << endl << endl;

    cout << "Printing String with help of iterator: " << endl;
    for (int i=0; i<name.length(); i++){
        cout << name[i];
    }
    cout << endl << endl;

    cout << "Length of string: " << name.length() << endl;
    
    cout << name << "   " << game << endl;
    game = name;
    cout << name << "   " << game << endl;

}