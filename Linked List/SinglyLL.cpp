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
            delete next;
            this->next = NULL;
        }
        cout << "Memory freed for the Node with data value: " << value << endl;
    }
};

class LinkedList{

    public:

    void InsertAtHead(Node* &head, Node* &tail, int d){
        Node* temp = new Node(d);
        if (head==NULL){
            head = temp;
            tail = temp;
        }
        else{
            temp->next = head;
            head = temp;
        }
    }
    
    void InsertAtTail(Node* &head, Node* &tail, int d){
        Node* temp = new Node(d);
        if (tail==NULL){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }
    
    void InsertAtPosition(Node* &head, Node* &tail, int position, int d){
    
        if (position==1){
            InsertAtHead(head, tail, d);
            return;
        }
        
        Node* temp = head;
        int count = 1;
    
        while (count < position-1){
            temp = temp->next;
            count++;
        }
    
        if (temp->next == NULL){
            InsertAtTail(head, tail, d);
        }
        else{
            Node* NodetoInsert = new Node(d);
            NodetoInsert->next = temp->next;
            temp->next = NodetoInsert;
        }
    }
    
    void DeleteNode(Node* &head, Node* &tail, int position){
    
        if (position==1){
            Node* temp = head;
            head = head->next;
            if (head==NULL){
                tail = NULL;
            }
            temp->next = NULL;
            delete temp;
        }
            
        else{
            Node* current = head;
            Node* previous = NULL;
            int count = 1;
    
            while (count < position){
                previous = current;
                current = current->next;
                count++;
            }
    
            if (current->next == NULL){
                tail = previous;
            }
            
            previous->next = current->next;
            current->next = NULL;
            delete current;
        }
    }
    
    void print(Node* &head){
    
        if (head==NULL){
            cout << "Linked List is Empty." << endl;
        }
        else{
            Node* temp = head;
            while (temp != NULL){
                cout << temp->data << "  ";
                temp = temp->next;
            }
            cout << endl;
        }
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
};