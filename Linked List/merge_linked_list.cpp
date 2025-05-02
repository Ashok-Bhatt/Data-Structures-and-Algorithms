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

Node* findMiddle(Node* &head){

    Node* slow = head;
    Node* fast = head->next;

    while (fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

Node* merge(Node* &head1, Node* &head2){

    if (head1==NULL)
        return head2;
    else if (head2==NULL)
        return head1;
    else{    
        Node* head = new Node(0);
        Node* temp = head;

        while (head1!=NULL && head2!=NULL){
            if (head1->data >= head2->data){
                temp->next = head2;
                temp = head2;
                head2 = head2->next;
            }
            else{
                temp->next = head1;
                temp = head1;
                head1 = head1->next;
            }
        }

        while (head1!=NULL){
            temp->next = head1;
            temp = head1;
            head1 = head1->next;
        }

        while (head2!=NULL){
            temp->next = head2;
            temp = head2;
            head2 = head2->next;
        }

        return head->next;
    }
}

void mergeSort(Node* &head){

    if (head==NULL || head->next==NULL){
        return;
    }

    Node* middle = findMiddle(head);

    Node* head1 = head;
    Node* head2 = middle->next;
    middle->next = NULL;
    
    mergeSort(head1);
    mergeSort(head2);

    head =  merge(head1,head2);
    
}

int main() {

    Node* head = NULL;
    Node* tail = NULL;

    InsertAtTail(head, tail, 32);
    InsertAtTail(head, tail, 23);
    InsertAtTail(head, tail, 90);
    InsertAtTail(head, tail, 2);
    InsertAtTail(head, tail, -52);
    InsertAtTail(head, tail, 6);

    cout << "Linked List before sorting: " << endl;
    print(head);

    mergeSort(head);

    cout << endl << "Linked List after sorting: " << endl;
    print(head);    
    
}