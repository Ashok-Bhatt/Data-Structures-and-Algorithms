#include <iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;
    Node* prev;

    Node(int d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node(){
        int value = this->data;
        
        if (this->next != NULL){
            delete this->next;
            this->next = NULL;
        }

        cout << "Memory freed for node with data value: " << value << endl;
    }

};

void insert(Node* &tail, int element, int d){

    Node* nodetoInsert = new Node(d);
    
    if (tail==NULL){
        tail = nodetoInsert;
        nodetoInsert->next = tail;
        nodetoInsert->prev = tail;
    }

    else{
        Node* current = tail;

        while (current->data != element){
            current = current->next;
        }

        nodetoInsert->next = current->next;
        current->next = nodetoInsert;
        current->next->prev = nodetoInsert;
        nodetoInsert->prev = current;
    }
}

void print(Node* &tail){

    if (tail==NULL){
        cout << "Empty Linked List." << endl;
        return;
    }
    
    Node* temp = tail;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }
    while (temp!=tail);
    cout << endl;
}

void deleteNode(Node* &tail, int value){

    if (tail==NULL){
        cout << "Linked List is empty. So deletion not possible." << endl;
    }

    else{
        Node* previous = tail;
        Node* current = tail->next;

        while (current->data != value){
            previous = current;
            current = current->next;
        }

        previous->next = current->next;

        if (current == previous){
            tail = NULL;
        }
        else if (current == tail){
            tail = previous;
        }
        
        current->next = NULL;
        previous->prev = current->prev;
        current->prev = NULL;
        delete current;
        
    }   
}

void printTail(Node* &tail){
    if (tail==NULL){
        cout << "Empty Linked List." << endl;
    }
    else{
        cout << tail->data << endl;
    }
}

int main() {

    Node* tail = NULL;
    int choice, element, value;
    
    do{
        
        cout << endl << "1. Insert Node    2. Print Linked List    3. Delete Node    4. Print Tail" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        switch(choice){
            case 1:{
                cout << "Enter tracing element and value of new node: ";
                cin >> element >> value;
                insert(tail, element, value);
                break;
            }
            case 2:{
                print(tail);
                break;
            }
            case 3:{
                cout << "Enter tracing element: ";
                cin >> element;
                deleteNode(tail, element);
                break;
            }
            case 4:{
                printTail(tail);
                break;
            }
        }
    } while (choice>=1 && choice<=4);
    
}