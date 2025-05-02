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

void insertAtHead(Node* &head, Node* &tail, int d){
    
    Node* NodetoInsert = new Node(d);
    
    if (head==NULL){
        head = NodetoInsert;
        tail = NodetoInsert;
        return;
    }

    NodetoInsert->next = head;
    head->prev = NodetoInsert;
    head = NodetoInsert;
    
}

void insertAtTail(Node* &head, Node* &tail, int d){

    Node* NodetoInsert = new Node(d);

    if (tail==NULL){
        head = NodetoInsert;
        tail = NodetoInsert;
        return;
    }

    tail->next = NodetoInsert;
    NodetoInsert->prev = tail;
    tail = NodetoInsert;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d){

    if (position==1){
        insertAtHead(head, tail, d);
        return;
    }

    Node* temp = head;
    int count = 1;

    while (count<position-1){
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL){
        insertAtTail(head, tail, d);
    }
    else{
        Node* NodetoInsert = new Node(d);
        NodetoInsert->next = temp->next;
        temp->next->prev = NodetoInsert;
        temp->next = NodetoInsert;
        NodetoInsert->prev = temp;
    }
}

void deleteNode(Node* &head, Node* &tail, int position){
    
    if (position==1){
        Node* temp = head;
        head = head->next;
        temp->next->prev = NULL;
        temp->next = NULL;
        delete temp;
    }

    else{
        Node* previous = NULL;
        Node* current = head;
        int count = 1;

        while (count < position){
            previous = current;
            current = current->next;
            count++;
        }

        if (current->next != NULL){
            current->next->prev = previous;
        }
        else{
            tail = previous;
        }
        previous->next = current->next;
        current->next = NULL;
        current->prev = NULL;
        delete current;
    }
}

void print(Node* &head){
    
    if (head==NULL){
        cout << "Linked List is empty." << endl;
    }
    
    Node* temp = head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void PrintHead(Node* head){
    if (head==NULL){
        cout << "Empty Linked List" << endl;
        return;
    }
    cout << head->data << endl;
}

void PrintTail(Node* tail){
    if (tail==NULL){
        cout << "Empty Linked List" << endl;
        return;
    }
    cout << tail->data << endl;
}

int main() {

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 35);
    insertAtHead(head, tail, 420);
    insertAtTail(head, tail, 0);
    insertAtHead(head, tail, 42);

    print(head);

    insertAtPosition(head, tail, 1, 67);
    print(head);

    insertAtPosition(head, tail, 2, 111);
    print(head);

    insertAtPosition(head, tail, 7, 827);
    print(head);

    insertAtPosition(head, tail, 3, 1);
    print(head);

    deleteNode(head, tail, 1);
    print(head);
    PrintHead(head);
    PrintTail(tail);

    deleteNode(head, tail, 7);
    print(head);
    PrintHead(head);
    PrintTail(tail);

    deleteNode(head, tail, 3);
    print(head);
    PrintHead(head);
    PrintTail(tail);
}