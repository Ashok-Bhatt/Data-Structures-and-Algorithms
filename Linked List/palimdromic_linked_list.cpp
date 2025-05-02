#include <iostream>
#include "SinglyLL.cpp"
using namespace std;

Node* findMiddle(Node* &head){

    Node* slow = head;
    Node* fast = head->next;

    while (fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* reverseHalf(Node* &middle){

    Node* previous = NULL;
    Node* current = middle->next;

    while (current!=NULL){
        Node* forward = current->next;
        current->next = previous;
        previous = current;
        current = forward;
    }

    return previous;
}

bool IsPalimdrome(Node* head1, Node* head2){
    
    while (head2!=NULL){
        if (head1->data == head2->data){
            head1 = head1->next;
            head2 = head2->next;
        }
        else{
            return false;
        }
    }

    return true;
}

int main() {

    LinkedList* l1 = new LinkedList();
    Node* head1 = NULL;
    Node* tail1 = NULL;

    l1->InsertAtTail(head1, tail1, 1);
    l1->InsertAtTail(head1, tail1, 6);
    l1->InsertAtTail(head1, tail1, 8);
    l1->InsertAtTail(head1, tail1, 8);
    l1->InsertAtTail(head1, tail1, 6);
    l1->InsertAtTail(head1, tail1, 1);

    cout << "Elements of given Linked List:" << endl;
    l1->print(head1);

    if (head1->next==NULL || head1->next->next== NULL)
        cout << endl << "Given Linked List is palimdromic." << endl;
    else{
        
        Node* middle = findMiddle(head1);
        middle->next = reverseHalf(middle);
    
        bool ans = IsPalimdrome(head1, middle->next);
        
        if (ans)
            cout << endl << "Given Linked List is palimdromic." << endl;
        else
            cout << endl << "Given Linked List is not a palimdromic." << endl;

        middle->next = reverseHalf(middle);
    }
    
    return 0;
}