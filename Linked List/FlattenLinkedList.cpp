#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* down;

    Node(int d){
        this->data = d;
        this->next = NULL;
        this->down = NULL;
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

void printDownWise(Node* &head){

    Node* temp1 = head;
    while (temp1 != NULL){
        if (temp1->down != NULL){
            Node* temp2 = temp1;
            while (temp2 != NULL){
                cout << temp2->data << " --> ";
                temp2 = temp2->down;
            }
            cout << endl;
        }
        temp1 = temp1->next;
    }
}

void InsertAtDown(Node* &head, int d){
    
    Node* temp = new Node(d);
    Node* ptr = head;
    
    while (ptr->down != NULL){
        ptr = ptr->down;
    }

    ptr->down = temp;
}

void mergeTwoList(Node* current, Node* forward){
    current->next = forward;
}

void mergeLinkedList(Node* head){

    if (head == NULL){
        return;
    }

    Node* current = head;
    Node* forward = head->next;
    current->next = NULL;
    
    while (current->down != NULL){
        current->next = current->down;
        current = current->down;
    }

    mergeLinkedList(forward);
    mergeTwoList(current, forward);

}

int main() {

    Node* head = NULL;
    Node* tail = NULL;

    InsertAtTail(head, tail, 3);
    InsertAtTail(head, tail, 5);
    InsertAtTail(head, tail, 10);
    InsertAtTail(head, tail, 30);


    // Assigning down pointers
    InsertAtDown(head, 4);
    InsertAtDown(head, 6);
    InsertAtDown(head, 12);
    InsertAtDown(head->next, 6);
    InsertAtDown(tail, 420);
    InsertAtDown(tail, 480);

    cout << "\nLinked List before merging: " << endl;
    print(head);
    printDownWise(head);

    cout << "\nLinked List after merging: " << endl;
    print(head);
    mergeLinkedList(head);
    print(head);
    
}