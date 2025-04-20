#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> leftSmallestOccurances(int histogram[], int size){

    vector<int> left(size);
    stack<int> index;
    index.push(-1);

    for (int i=0; i<size; i++){
        while (index.top()!=-1 && histogram[index.top()]>=histogram[i]){
            index.pop();
        }
        left[i] = index.top();
        index.push(i);
    }

    return left;

}

vector<int> rightSmallestOccurances(int histogram[], int size){

    vector<int> right(size);
    stack<int> index;
    index.push(-1);

    for (int i=size-1; i>=0; i--){
        while (index.top()!=-1 && histogram[index.top()]>=histogram[i]){
            index.pop();
        }
        right[i] = index.top();
        index.push(i);
    }

    return right;

}

int main(){

    int histogram[6] = {3,6,1,8,4,5};
    int size = sizeof(histogram)/sizeof(histogram[0]);


    // Brute Force :        T.C.: O(n^2)      S.C.:O(1)
    int ans1 = 0;
    for (int i=0; i<size; i++){

        int left = i, right=i;
        while (left>=0 && histogram[left]>=histogram[i]){
            left--;
        }
        while (right<size && histogram[right]>=histogram[i]){
            right++;
        }

        int area = histogram[i]*(right-left-1);
        ans1 = max(ans1, area);
    }

    cout << "Area of largest rectangle in histogram using brute force solution: " << ans1 << endl << endl;


    // Optimised Solution:      T.C.: O(n)      S.C.: O(n)
    int ans2 = 0;

    vector<int> left = leftSmallestOccurances(histogram, size);
    vector<int> right = rightSmallestOccurances(histogram, size);

    for (int i=0; i<size; i++){

        if (right[i]==-1){
            right[i] = size;
        }

        int area = histogram[i]*(right[i]-left[i]-1);
        ans2 = max(ans2,area);

    }

    cout << "Area of largest rectangle in histogram using stack: " << ans2 << endl << endl;

}