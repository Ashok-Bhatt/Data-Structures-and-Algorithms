#include <bits/stdc++.h>
using namespace std;

class Heap{

    public:
    int arr[100];
    int size;

    Heap(){
        arr[0] = -1;
        size = 0;
    }

    void insertion (int val){

        size++;
        int index = size;
        arr[index] = val;

        while (index>1){
            int parent = index/2;
            if (arr[parent] > arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void deletion(){
        
        if (size<=0){
            cout << "Empty Heap" << endl;
            return;
        }

        swap(arr[1],arr[size]);
        size--;

        int index = 1;
        while (index<=size){

            int left = 2*index;
            int right = 2*index+1;
            int minimum = index;

            if (left<=size && arr[left] < arr[minimum]){
                minimum = left;
            }
            if (right<=size && arr[right] < arr[minimum]){
                minimum = right;
            }

            if (index!=minimum){
                swap(arr[index],arr[minimum]);
                index = minimum;
            }
            else{
                return;
            }
        }
    }

    void print(){
        cout << "All nodes of heap: " << endl;
        for (int i=1; i<=size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main(){

    Heap* h1 = new Heap();
    h1->insertion(12);
    h1->insertion(10);
    h1->insertion(13);
    h1->insertion(34);
    h1->insertion(32);
    h1->insertion(100);

    h1->print();

    while (h1->size>0){
        h1->deletion();
        h1->print();
    }
}