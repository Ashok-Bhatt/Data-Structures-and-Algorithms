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

void print(Node* &head){

    if (head==NULL){
        cout << "Linked List is Empty." << endl;
    }
    else{
        Node* temp = head;
        while (temp != NULL){
            cout << temp->data << "--->";
            temp = temp->next;
        }
        cout << endl;
    }
}

void reverse(Node* &head, Node* &previous, Node* &current){

    if (current == NULL){
        head = previous;
        return;
    }
    
    Node* forward = current->next;
    reverse(head, current, forward);
    current->next = previous;
    
}

Node* reverse1(Node* &head){

    if (head==NULL || head->next==NULL){
        return head;
    }

    Node* chottaHead = reverse1(head->next);
    head->next->next = head;
    head->next = NULL;
    return chottaHead;
}

int main() {

    Node* head = new Node(5);
    Node* temp = head;
    int num;

    for (int i=0; i<4; i++){
        cout << "Enter number:";
        cin >> num;
        Node* itr = new Node(num);
        temp->next = itr;
        temp = temp->next;
    }

    cout << endl << "Original Linked List:" << endl;
    print(head);

    /* 
    Node* previous = NULL;
    Node* current = head;

    while (current != NULL){
        Node* forward = current->next;
        current->next = previous;
        previous = current;
        current = forward;
    }

    //head = previous;

    cout << endl << "Reversed Linked List (Iterative Approach):" << endl;
    print(previous);
 */

/* 
    Node* previous = NULL;
    Node* current = head;

    reverse(head, previous, current);

    cout << endl << "Reversed Linked List (Recursive Approach 1):" << endl;
    print(head);
 */

    Node* head1 = reverse1(head);
    cout << "Reversed Linked List (Recursive Approach 2):" << endl;
    print(head1);
    
}