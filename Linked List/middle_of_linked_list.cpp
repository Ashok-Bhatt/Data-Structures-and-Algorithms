#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory freed for the Node with data value: " << value << endl;
    }
};

void InsertAtHead(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

void InsertAtTail(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d);
    if (tail == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void InsertAtPosition(Node *&head, Node *&tail, int position, int d)
{

    if (position == 1)
    {
        InsertAtHead(head, tail, d);
        return;
    }

    Node *temp = head;
    int count = 1;

    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        InsertAtTail(head, tail, d);
    }
    else
    {
        Node *NodetoInsert = new Node(d);
        NodetoInsert->next = temp->next;
        temp->next = NodetoInsert;
    }
}

void DeleteNode(Node *&head, Node *&tail, int position)
{

    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }
        temp->next = NULL;
        delete temp;
    }

    else
    {
        Node *current = head;
        Node *previous = NULL;
        int count = 1;

        while (count < position)
        {
            previous = current;
            current = current->next;
            count++;
        }

        if (current->next == NULL)
        {
            tail = previous;
        }

        previous->next = current->next;
        current->next = NULL;
        delete current;
    }
}

void print(Node *&head)
{

    if (head == NULL)
    {
        cout << "Linked List is Empty." << endl;
    }
    else
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void PrintHead(Node *head)
{
    if (head == NULL)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    cout << head->data << endl;
}

void PrintTail(Node *tail)
{
    if (tail == NULL)
    {
        cout << "Empty Linked List" << endl;
        return;
    }
    cout << tail->data << endl;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    InsertAtTail(head, tail, 10);
    InsertAtTail(head, tail, 20);
    InsertAtTail(head, tail, 30);
    InsertAtTail(head, tail, 40);
    InsertAtTail(head, tail, 50);
    InsertAtTail(head, tail, 60);

    if (head == NULL)
    {
        cout << "Empty Linked List" << endl;
    }
    else if (head->next == NULL)
    {
        cout << head->data << endl;
    }
    else
    {

        /*
        cout << endl << "Approach 1:" << endl;
        int count = 0;
        Node* temp = head;

        while (temp != NULL){
            count++;
            temp = temp->next;
        }

        temp = head;
        for (int i=0; i<count/2; i++){
            temp = temp->next;
        }

        cout << "Data value of middle node: " << temp->data << endl;
        */

        cout << endl
             << "Approach 2:" << endl;
        Node *temp1 = head;
        Node *temp2 = head->next;

        while (temp2 != NULL)
        {
            temp2 = temp2->next;
            if (temp2 != NULL)
            {
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        cout << "Data value of middle node: " << temp1->data << endl;
    }
}