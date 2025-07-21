#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *prev, *next;

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

class LinkedList{
public:
    Node *head, *tail;

    LinkedList(){
        head = tail = NULL;
    }

    Node* getHead(){
        return head;
    }

    Node* getTail(){
        return tail;
    }

    void insert(Node* newNode){
        if (tail == NULL){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = tail->next;
        }
    }

    int remove(Node* node){
        Node *prevNode = node->prev, *nextNode = node->next;
        if (prevNode) prevNode->next = nextNode;
        else head = head->next;
        if (nextNode) nextNode->prev = prevNode;
        else tail = tail->prev;
        node->next = node->prev = NULL;
        cout << "Deleted: " << node->data << "         ";
        return node->data;
    }

    bool isEmpty(){
        return head==NULL;
    }
};

class LFUCache {
public:
    int cacheSize, capacity, minFreq;
    unordered_map<int, pair<pair<int, int>, Node*>> keyPair;
    map<int, LinkedList*> frequency;

    LFUCache(int capacity) {
        this->cacheSize = 0;
        this->capacity = capacity;
        this->minFreq = 0;
    }

    void printLists(){
        for (auto it : frequency){
            cout << it.first << " -> ";
            Node* head = it.second->getHead();
            while (head) {
                cout << head->data << " ";
                head = head->next;
            }
            cout << "         ";
        }
        cout << endl;
    }
    
    int get(int key) {
        if (keyPair.find(key) == keyPair.end()){
            cout << "Get : Nothing" << endl;
            return -1;
        } else {
            int value = keyPair[key].first.first, freq = keyPair[key].first.second;
            Node* node = keyPair[key].second;

            frequency[freq]->remove(node);
            if (frequency.find(freq+1) == frequency.end()) frequency[freq+1] = new LinkedList();
            frequency[freq+1]->insert(node);
            keyPair[key].first.second++;
            while (frequency[minFreq]->isEmpty()) minFreq++;

            cout << "Get : " << value << endl;
            printLists();
            return value;
        }
    }
    
    void put(int key, int value) {

        if (keyPair.find(key) == keyPair.end()){
            Node* newNode = new Node(key);
            if (cacheSize < capacity){
                keyPair[key] = {{value, 1}, newNode};
                minFreq = 1;
                cacheSize++;
                if (frequency.find(minFreq) == frequency.end()) frequency[minFreq] = new LinkedList();
                frequency[1]->insert(newNode);
            } else {
                keyPair[key] = {{value, 1}, newNode};
                int deletedKey = frequency[minFreq]->remove(frequency[minFreq]->head);
                keyPair.erase(deletedKey);
                if (frequency.find(1) == frequency.end()) frequency[minFreq] = new LinkedList();
                frequency[1]->insert(newNode);
                minFreq = 1;
            }
        } else {
            int value = keyPair[key].first.first, freq = keyPair[key].first.second;
            Node* node = keyPair[key].second;

            frequency[freq]->remove(node);
            if (frequency.find(freq+1) == frequency.end()) frequency[freq+1] = new LinkedList();
            frequency[freq+1]->insert(node);
            keyPair[key].first.second++;
            keyPair[key].first.first = 1;
            while (frequency[minFreq]->isEmpty()) minFreq++;
        }
        
        cout << "Put : " << key << endl;
        printLists();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){

    LFUCache* lfuCache = new LFUCache(2);
    lfuCache->put(1,1);
    lfuCache->put(2,2);
    lfuCache->get(1);
    lfuCache->put(3,3);
    lfuCache->get(2);
    lfuCache->get(3);
    lfuCache->put(4,4);
    lfuCache->get(1);
    lfuCache->get(3);
    lfuCache->get(4);
}