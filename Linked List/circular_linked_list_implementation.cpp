#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
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
    }

    else{
        Node* current = tail;

        while (current->data != element){
            current = current->next;
        }

        nodetoInsert->next = current->next;
        current->next = nodetoInsert;
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

    print(tail);
    printTail(tail);
    
    insert(tail, 3, 1);
    print(tail);
    printTail(tail);

    insert(tail, 1, 420);
    print(tail);
    printTail(tail);

    insert(tail, 1, 240);
    print(tail);
    printTail(tail);
    
    insert(tail, 240, 0);
    print(tail);
    printTail(tail);

    deleteNode(tail, 1);
    deleteNode(tail, 420);
    deleteNode(tail, 240);

    print(tail);
    printTail(tail);
    deleteNode(tail, 0);
    
    print(tail);
    printTail(tail);

    deleteNode(tail, 23847);
    
}