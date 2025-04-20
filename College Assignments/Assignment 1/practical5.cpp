
/* 
Question: Implement a Stack using two queues q1 and q2. 
operations vector is given. If element of the vector is -1 then pop the element else push that element
 */

#include <bits/stdc++.h>
using namespace std;

int getTop(vector<int>& operations){

    queue<int> q1, q2;
    int n = operations.size();

    for (int i=0; i<n; i++){
        if (operations[i] == -1){

            // pushing all elements of q1 except the last one
            int size = q1.size();
            for (int j=1; j<=size; j++){
                if (j != size){
                    q2.push(q1.front());
                }
                q1.pop();
            }

            // pushing back all the elements of q2 back to the q1
            for (int j=1; j<size; j++){
                q1.push(q2.front());
                q2.pop();
            }
        } else {
            q1.push(operations[i]);
        }
    }

    while (q1.size() > 1){
        q2.push(q1.front());
        q1.pop();
    }
    return q1.front();
}

int main(){
    vector<int> operations = {2,6,4,-1,6,4,5,3,-1,-1,3,-1,-1};
    cout << "Top element of the created stack: " << getTop(operations) << endl;
}