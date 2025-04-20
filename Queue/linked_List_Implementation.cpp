#include <iostream>
using namespace std;

class QueueNode{

    public:
    int data;
    QueueNode* next;

    QueueNode(int data){
        this->data = data;
        next = NULL;
    }

};

class Queue {

    public:
    QueueNode* front = NULL;
    QueueNode* rear = NULL;
    int size = 0;

    bool isEmpty(){
        if (front==NULL){
            return 1;
        }
        return 0;
    }

    int getFront(){
        if (isEmpty()){
            return -1;
        }
        return front->data;
    }

    int getRear(){
        if (isEmpty()){
            return -1;
        }
        return rear->data;
    }

    int getSize(){
        return size;
    }

    void enqueue(int data){

        QueueNode* newNode = new QueueNode(data);

        if (isEmpty()){
            front = newNode;
            rear = newNode;
            size =1;
            return;
        }

        rear->next = newNode;
        rear = newNode;
        size = size + 1;

    }

    int dequeue(){

        if (isEmpty()){
            return -1;
        }

        int data = getFront();
        QueueNode* nextFront = front->next;
        front->next = NULL;
        delete front;
        front = nextFront;
        size = size-1;

        if (getSize() == 0){
            rear = NULL;
        }
        
        return data;

    }

};

int main () {

    Queue* q1 = new Queue();

    q1->enqueue(34);
    cout << "Is Empty: " << q1->isEmpty() << endl;
    cout << "Front: " << q1->getFront() << "     Rear: " << q1->getRear() << "    Size: " << q1->getSize() << endl;

    q1->enqueue(12);
    cout << "Front: " << q1->getFront() << "     Rear: " << q1->getRear() << "    Size: " << q1->getSize() << endl;

    cout << "Dequeued Element: " << q1->dequeue() << endl;
    cout << "Front: " << q1->getFront() << "     Rear: " << q1->getRear() << "    Size: " << q1->getSize() << endl;

    q1->enqueue(45);
    q1->enqueue(100);
    cout << "Front: " << q1->getFront() << "     Rear: " << q1->getRear() << "    Size: " << q1->getSize() << endl;

    cout << "Dequeued Element: " << q1->dequeue() << endl;
    cout << "Dequeued Element: " << q1->dequeue() << endl;
    cout << "Dequeued Element: " << q1->dequeue() << endl;
    cout << "Is Empty: " << q1->isEmpty() << endl;
    cout << "Dequeued Element: " << q1->dequeue() << endl;

}