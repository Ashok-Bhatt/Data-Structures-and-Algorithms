#include <iostream>
using namespace std;

class Stack{
    public:
    int top;
    int* arr;
    int size;

    Stack(int size){
        this->size = size;
        top = -1;
        arr = new int[size];
    }

    void push(int element){
        if (size-top > 1){
            top++;
            arr[top] = element;
            cout << element << " is pushed into stack." << endl;
        }
        else{
            cout << "Stack Overflow!" << endl;
        }
    }

    void pop(){
        if (top>-1){
            int element = arr[top];
            top--;
            cout << element << " popped out of stack." << endl;
        }
        else{
            cout << "Stack Underflow!" << endl;
        }
    }

    void peek(){
        if (top>-1)
            cout << "Top Element: " << arr[top] << endl;
        else
            cout << "Stack is Empty! " << endl;
    }

    void isEmpty(){
        if (top == -1)
            cout << "Stack is empty! " << endl;
        else
            cout << "Stack is not empty! " << endl;
    }

};

int main(){

    Stack s1 = Stack(3);

    s1.push(5);
    s1.peek();
    s1.push(2);
    s1.push(4);
    s1.push(420);
    s1.peek();
    s1.pop();
    s1.peek();
    s1.pop();
    s1.isEmpty();
    s1.pop();
    s1.isEmpty();

}