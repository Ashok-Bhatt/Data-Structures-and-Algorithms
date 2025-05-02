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
        cout << "Memory freed for node with data: " << value << endl;
    }
};

// void insertAtTail(Node* &head, Node* &tail, int d){

//     Node* NodetoInsert = new Node(d);

//     if (tail==NULL){
//         head = NodetoInsert;
//         tail = NodetoInsert;
//         return;
//     }

//     tail->next = NodetoInsert;
//     NodetoInsert->prev = tail;
//     tail = NodetoInsert;
// }

void print(Node* &head){
    
    if (head==NULL){
        cout << "Linked List is empty." << endl;
    }
    
    Node* temp = head;
    while (temp != NULL){
        cout << temp->data << " --> ";
        temp = temp->next;
    }
    cout << endl;
}

void reversePrint(Node* &tail){
    if (tail==NULL){
        cout << "Linked List is empty." << endl;
    }
    
    Node* temp = tail;
    while (temp != NULL){
        cout << temp->data << " --> ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {

    Node* head = new Node(420);
    Node* tail = head;
    Node* itr = head;

    for (int i=0; i<4; i++){
        int num;
        cout << "Enter number: ";
        cin >> num;

        Node* temp = new Node(num);
        itr->next = temp;
        temp->prev = itr;
        tail = temp;
        itr = itr->next;
    }

    cout << "Before reversing:" << endl;
    print(head);
    reversePrint(tail);

    Node* previous = NULL;
    Node* current = head;
    Node* forward = NULL;

    while (current != NULL){
        forward = current->next;
        current->next = previous;
        current->prev = forward;
        previous = current;
        current = forward;
    }

    cout << endl << "After reversing:" << endl;
    print(tail);
    reversePrint(head);
    
}