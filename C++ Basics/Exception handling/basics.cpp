#include <bits/stdc++.h>
using namespace std;

class Bank{

    public:
    int balance, account_no;
    string user_name;

    Bank(string user_name, int balance, int account_no){
        this->user_name = user_name;
        this->balance = balance;
        this->account_no = account_no;
    } 

    void deposit(int amount){

        if (amount <=0) throw "Amount Should be positive number";
        
        balance = balance + amount;
        cout << amount << " deposited! " << endl;
        cout << "Current balance: " << balance << endl << endl;

    }

    void withdraw(int amount){

        if (amount <=0) throw "Amount Should be positive number";
        else if (amount > balance) throw "This amount not present";

        balance = balance - amount;
        cout << amount << " Withdrawn! " << endl;
        cout << "Current balance: " << balance << endl << endl;

    }

};

int main() {

    // Sometimes our code can cause error during runtime like dividing by zero, trying to dynamically access a large amount of data, etc. which is known as runtime exception

    // It is important as runtime errors can be tedious to debug during debugging

    /* 
    try: It represents a block of code that may went through an exception placed inside try block

    catch: It represents a block of code that is executed if a particular block of code is executed

    throw: It contains a block of code that will throw an exception 
    */

   Bank* user = new Bank("Ashok", 6000, 100);

   try{
        user->deposit(3000);    // Executes smoothly
        user->withdraw(6000);   // Executes smoothly
        user->withdraw(10000);  // This line will give error message
   } catch (const char *e){
        cout << "Exception Occurred: " << e << endl;
   }


   // Why try...catch... is needed if exception can be resolved using if...else... ?

    try {
        int *p = new int[100000000000000];
        cout << "Memory allocation successful." << endl;
        delete[] p;
    } catch (const exception &e){
        cout << "Exception occurred at line 67 " << e.what() << endl;
    }

}