#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> leftSmallestOccurance(int area[], int size){

    vector<int> left(size);
    stack<int> balance;
    balance.push(-1);

    for (int i=0; i<size; i++){
        while (balance.top()!=-1 && area[balance.top()]>=area[i]){
            balance.pop();
        }
        left[i] = balance.top();
        balance.push(i);
    }

    return left;

}

vector<int> rightSmallestOccurance(int area[], int size){

    vector<int> right(size);
    stack<int> balance;
    balance.push(-1);

    for (int i=size-1; i>=0; i--){
        while (balance.top()!=-1 && area[balance.top()]>=area[i]){
            balance.pop();
        }
        right[i] = balance.top();
        balance.push(i);
    }

    for (int i=0; i<size; i++){
        if (right[i]==-1){
            right[i] = size;
        }
    }

    return right;

}

int findArea(int area[], int size){

    vector<int> left = leftSmallestOccurance(area, size);
    vector<int> right = rightSmallestOccurance(area, size);

    int maxarea = 0;
    for (int i=0; i<size; i++){
        int currentArea = area[i]*(right[i]-left[i]-1);
        maxarea = max(maxarea, currentArea);
    }

    return maxarea;

}

int main(){

    int area[4][4] = {{1,1,1,0},
                    {1,1,1,1},
                    {1,1,1,1},
                    {1,0,1,0}};
    
    int size = sizeof(area[0])/sizeof(area[0][0]);
    int maxArea = findArea(area[0],size);

    for (int i=1; i<size; i++){
        for (int j=0; j<size; j++){
            if (area[i][j]==1){
                area[i][j] = area[i][j] + area[i-1][j];
            }
        }

        maxArea = max(maxArea, findArea(area[i], size));
    }

    cout << "Size of largest rectangle with all 1's: " << maxArea << endl;
    return 0;

}