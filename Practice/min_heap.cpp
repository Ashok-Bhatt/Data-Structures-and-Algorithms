#include <bits/stdc++.h>
using namespace std;

class MinHeap{
public:
    vector<int> arr;
    int index, size;

    MinHeap(int n){
        arr.resize(n);
        this->index = 0;
        this->size = n;
    }

    int top(){
        if (index==0) throw runtime_error("No top present");
        return arr[0];
    }

    int getSize(){
        return index;
    }

    void push(int val){
        if (index==size) throw runtime_error("Min Heap size exceeded");
        int temp = index;
        arr[index] = val;
        index++;

        while (temp>0 && arr[(temp-1)/2]>arr[temp]){
            swap(arr[temp], arr[(temp-1)/2]);
            temp = (temp-1)/2;
        }
    }

    void pop(){
        if (index==0) throw runtime_error("Min Heap is empty");
        swap(arr[0], arr[index-1]);
        index--;

        int temp = 0;
        while (temp < index){
            int smallest = temp;
            int leftIndex = 2*index+1, rightIndex=2*index+2;

            if (leftIndex<index && arr[leftIndex] < arr[smallest]){
                smallest = leftIndex;
            }

            if (rightIndex<index && arr[rightIndex] < arr[smallest]){
                smallest = rightIndex;
            }

            swap(arr[temp], arr[smallest]);
            if (temp==smallest) break;
            temp = smallest;
        }
    }
};

int main(){
    MinHeap* minHeap = new MinHeap(2048);
    // cout << "Top: " << minHeap->top() << endl;
    minHeap->push(20);
    cout << "Top: " << minHeap->top() << endl;
    minHeap->push(2);
    minHeap->push(18);
    cout << "Top: " << minHeap->top() << endl;
    cout << "Size: " << minHeap->getSize() << endl;
    minHeap->pop();
    cout << "Top: " << minHeap->top() << endl;
}