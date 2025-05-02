#include "SinglyLL.cpp"
#include <iostream>
using namespace std;

Node* reverse(Node *head) {

  Node *previous = NULL;
  Node *current = head;
  Node *forward = NULL;

  while (current != NULL) {
    forward = current->next;
    current->next = previous;
    previous = current;
    current = forward;
  }

  return previous;
}

void add(Node *head1, Node *head2, Node* &head3) {

  Node* temp = head3;
  int carry = 0;

  while (head1 != NULL || head2 != NULL || carry != 0) {

      Node* newNode = new Node(0);
      int value = carry;
      
      if (head1 != NULL){
          value = value + head1->data;
          head1 = head1->next;
      }

      if (head2 != NULL){
          value = value + head2->data;
          head2 = head2->next;
      }
      
      newNode->data = value%10;
      carry = value/10;
      
      if (head3==NULL){
          temp = newNode;
          head3 = temp;
      }
      else{
          temp->next = newNode;
          temp = newNode;
      }
    }
}

int main() {

  LinkedList *l1 = new LinkedList();
  Node *head1 = NULL;
  Node *tail1 = NULL;

  LinkedList *l2 = new LinkedList();
  Node *head2 = NULL;
  Node *tail2 = NULL;

  l1->InsertAtTail(head1, tail1, 9);
  l1->InsertAtTail(head1, tail1, 9);
  l1->InsertAtTail(head1, tail1, 9);

  l2->InsertAtTail(head2, tail2, 8);
  l2->InsertAtTail(head2, tail2, 8);

  cout << "Number represented by Linked List 1:" << endl;
  l1->print(head1);

  cout << endl << "Number represented by Linked List 2:" << endl;
  l2->print(head2);

  head1 = reverse(head1);
  head2 = reverse(head2);

  LinkedList* l3 = new LinkedList();
  Node* head3 = NULL;
    
  add(head1, head2, head3);
  head3 = reverse(head3);

  cout << endl << "Number represented by sum of number represented by Linked List 1 and Linked List 2: " << endl;
  l3->print(head3);
}