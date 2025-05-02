#include <iostream>
#include <unordered_map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* random;

    Node(int d){
        this->data = d;
        this->next = NULL;
        this->random = NULL;
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

int main() {

    Node* head1 = NULL;
    Node* tail1 = NULL;

    InsertAtTail(head1, tail1, 4);
    InsertAtTail(head1, tail1, 23);
    InsertAtTail(head1, tail1, 100);
    InsertAtTail(head1, tail1, 34);

    // Assigning some random pointers
    head1->random = head1->next->next;
    head1->next->random = head1->next->next;
    head1->next->next->random = tail1;
    tail1->random = head1;


    // Copying the Original Linked List with only next pointers
    Node* head2 = NULL;
    Node* tail2 = NULL;
    Node* ptr = head1;
    unordered_map<Node*, Node*> mapping;

    while (ptr!=NULL){
        int value = ptr->data;
        InsertAtTail(head2, tail2, value);
        mapping[ptr] = tail2;
        ptr = ptr->next;
    }


    // Assigning the random pointers in copied linked list
    Node* ptr1 = head1;
    Node* ptr2 = head2;

    while(ptr1 != NULL){
        ptr2->random = mapping[ptr1->random];
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    // Printing Linked List - I
    head1->random = head1->next;
    ptr1 = head1;
    while (ptr1 != NULL){
        cout << "Data: " << ptr1->data << "    Random Pointer: " << ptr1->random->data << endl;
        ptr1 = ptr1->next;
    }
    cout << endl;

    // Printing Linked List - II
    ptr2 = head2;
    while (ptr2 != NULL){
        cout << "Data: " << ptr2->data << "    Random Pointer: " << ptr2->random->data << endl;
        ptr2 = ptr2->next;
    }
    cout << endl;
   
}