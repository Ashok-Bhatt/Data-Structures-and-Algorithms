#include <iostream>
using namespace std;

class Hero{

    // By-default private
    char password[8];

    public:
    int health;
    char level;

    void getPassword(){
        cout << password;
    }

    void setPassword(){
        cout << endl << "Enter the password:" << endl;
        for (int i=0; i<8; i++){
            cin >> password[i];
        }
    }
};

int main() {

    Hero h1;
    h1.health = 90;
    h1.level = 'S';
    //h1.password;  ---> not possible to access private data members

    cout << h1.health << endl;
    cout << h1.level << endl;
    h1.getPassword();

    h1.setPassword();

    cout << endl << "New password:" << endl;
    h1.getPassword();
    
}