#include <iostream>
using namespace std;

class Stack{

    public:
    int* arr;
    int top1;
    int top2;
    int size;

    Stack(int size){
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int element){
        if (top2-top1 > 1){
            top1++;
            arr[top1] = element;
        }
        else{
            cout << "Stack overflow! " << endl;
        }
    }

    void push2(int element){
        if (top2-top1 > 1){
            top2--;
            arr[top2] = element;
        }
        else{
            cout << "Stack overflow! " << endl;
        }
    }

    void pop1(){
        if (top1>-1)
            top1--;
        else
            cout << "Stack underflow! " << endl;
    }

    void pop2(){
        if (top2<size)
            top2++;
        else
            cout << "Stack underflow! " << endl;
    }

    void peek1(){
        if (top1>-1)
            cout << "Top element of stack1: " << arr[top1] << endl;
        else
            cout << "Stack1 is empty! " << endl;
    }

    void peek2(){
        if (top2<size)
            cout << "Top element of stack2: " << arr[top2] << endl;
        else
            cout << "Stack2 is empty! " << endl;
    }

};

int main(){

    Stack* s1 = new Stack(4);
    s1->peek1();
    s1->peek2();
    s1->push1(2);
    s1->push2(4);
    s1->push2(30);
    s1->peek1();
    s1->peek2();
    s1->push2(56);
    s1->peek2();
    s1->push2(100);
    s1->peek2();
    s1->push1(23);
    s1->peek1();
    s1->peek2();
    s1->pop1();
    s1->peek1();
    s1->pop1();
    s1->pop1();
    s1->pop2();
    s1->pop2();
    s1->pop2();

}