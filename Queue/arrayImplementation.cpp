#include<iostream>
using namespace std;

class stack{

    public:
    int size;
    int arr[1000];
    int front = -1;
    int rear = -1;

    stack(int n){
        this->size = n;
    }

    void push(int element){

        if (rear==size-1){
            cout << "Queue Overflow! " << endl;
        }
        else {
            rear++;
            if (rear==0){
                front = 0;
            }
            arr[rear] = element;
        }
    }

    void pop(){
        if (front==-1){
            cout << "Queue Underflow! " << endl;
        }
        else{
            int element = arr[front];
            front++;
            cout << element << " popped from queue." << endl;
            if (rear == front-1){
                rear = -1;
                front = -1;
            }
        }
    }

    void showFront(){
        if (front==-1){
            cout << "Queue is Empty" << endl;
        }
        else{
            cout << "Front Element: " << arr[front] << endl;
        }
    }

    void isFull(){
        if (rear==size-1){
            cout << "Queue is full" << endl;
        }
        else{
            cout << "Queue is not full" << endl;
        }
    }

    void isEmpty(){
        if (rear==-1){
            cout << "Queue is Empty" << endl;
        }
        else{
            cout << "Queue is not Empty" << endl;
        }
    }

};

int main() { 

    stack s1(3);
    s1.push(3);
    s1.push(6);
    s1.pop();
    s1.push(1);
    s1.isEmpty();
    s1.showFront();
    s1.pop();
    s1.pop();
    s1.push(9);
    s1.pop();
    s1.showFront();
    s1.push(4);
    s1.push(3);
    s1.isFull();
    s1.push(100);
    s1.push(200);

}