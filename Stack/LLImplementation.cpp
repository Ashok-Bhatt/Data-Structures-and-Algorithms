#include <iostream>
#include <vector>
using namespace std;

class StackNode{

    public:
    StackNode* next;
    int data;

    StackNode(int data){
        this->data = data;
        next = NULL;
    }

};

class Stack{

    public:
    StackNode* head;
    int top;
    int size;

    Stack(int size) {
        this->size = size;
        top = -1;
        head = NULL;
    }

    void push(StackNode* &head, int element, int top){
        if (this->size - this->top > 1){
            StackNode* newNode = new StackNode(element);
            this->top++;
            if (head==NULL)
                head = newNode;
            else{
                StackNode* temp = head;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = newNode;
            }
        }
    }

    void pop(StackNode* &head, int top){
        if (head->next == NULL){
            delete head;
            head = NULL;
            this->top--;
        }
        else if (head!=NULL){
            StackNode* temp = head;
            while (temp->next->next != NULL)
                temp = temp->next;
            StackNode* nodetoDelete = temp->next;
            temp->next = NULL;
            delete nodetoDelete;
            this->top--;
        }
    }

    void peek(StackNode* &head){
        if (head==NULL)
            cout << "Stack is empty. " << endl;
        else{ 
            StackNode* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            cout << "Data of element at top of stack: " << temp->data << endl;
        }
    }

    bool isEmpty(int top){
        if (top==-1)
            return true;
        return false;
    }

};

int main(){

    Stack* s1 = new Stack(3);
    s1->peek(s1->head);
    s1->push(s1->head, 56, s1->top);
    s1->peek(s1->head);
    s1->push(s1->head, 4, s1->top);
    s1->push(s1->head, 5, s1->top);
    s1->push(s1->head, 100, s1->top);
    s1->push(s1->head, 200, s1->top);
    s1->peek(s1->head);
    s1->pop(s1->head, s1->top);
    s1->pop(s1->head, s1->top);
    s1->peek(s1->head);
    cout << "Is stack empty: " << s1->isEmpty(s1->top) << endl;
    s1->pop(s1->head, s1->top);
    cout << "Is stack empty: " << s1->isEmpty(s1->top) << endl;
    s1->peek(s1->head);  

}