#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
public:
    vector<int> arr;
    int n;
    vector<int> segment;

    SegmentTree(vector<int> arr){
        this->arr = arr;
        n = arr.size();
        segment.resize(4*n);
        this->BuildSegmentTree(0, n-1, 0);
    }

    void BuildSegmentTree(int low, int high, int index){

        if (low == high){
            segment[index] = arr[low];
            return;
        } 

        int mid = low + (high - low)/2;
        BuildSegmentTree(low, mid, index*2+1);
        BuildSegmentTree(mid+1, high, index*2+2);
        segment[index] = min(segment[2*index+1], segment[2*index+2]);
    }

    int queryRange(int low, int high, int index, int left, int right){

        if (left<=low && right>=high){
            // Complete overlapping
            return segment[index];
        } else if (right < low || left > high){
            // No overlapping
            return INT_MAX;
        } else {
            // partial overlapping
            int mid = low + (high - low)/2;
            int leftSubTree = queryRange(low, mid, index*2+1, left, right);
            int rightSubTree = queryRange(mid+1, high, index*2+2, left, right);
            return min(leftSubTree, rightSubTree);
        }
    }

    void updateNode(int low, int high, int index, int i, int value){

        if (low == high){
            segment[index] = value;
            return;
        }

        int mid = low + (high - low) / 2;
        if (i <= mid){
            updateNode(low, mid, index*2+1, i, value);
        } else {
            updateNode(mid+1, high, index*2+2, i, value);
        }
        segment[index] = min(segment[index*2+1], segment[index*2+2]);
    }

    int query(int left, int right){
        if (left<0 || left>=n || right<0 || right>=n){
            throw ("Invalid Index");
        }
        return this->queryRange(0, n-1, 0, left, right);
    }

    void update(int index, int value){
        if (index<0 || index>=n){
            throw ("Invalid Index");
        }
        arr[index] = value;
        this->updateNode(0, n-1, 0, index, value);
    }

};

int main(){

    int n, k;
    cin >> n;

    vector<int> arr(n);
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    SegmentTree* tree = new SegmentTree(arr);

    cin >> k;
    for (int i=0; i<k; i++){
        int queryType, input1, input2;
        cin >> queryType;
        cin >> input1;
        cin >> input2;
        if (queryType == 1){
            try{
                int minimumValue =  tree->query(input1, input2);
                cout << "Minimum value in index range " << input1 << " & " << input2 << " is " << minimumValue << endl;
            } catch (char* e){
                cout << "Exception: " << e << endl;
            }
        } else {
            try{
                tree->update(input1, input2);
            } catch (char* e){
                cout << "Exception: " << e << endl;
            }
        }
    }
    return 0;
}