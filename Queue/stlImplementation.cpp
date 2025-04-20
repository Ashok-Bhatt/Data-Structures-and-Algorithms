#include <iostream>
#include <queue>
using namespace std;

int main() {

    queue<int> ans;
    ans.push(45);
    ans.push(2);
    cout << "Queue front: " << ans.front() << endl;
    ans.pop();
    ans.push(100);
    cout << "Queue front: " << ans.front() << endl;
    ans.pop();
    cout << "Is Queue empty: " << ans.empty() << endl;
    ans.pop();
    cout << "Is Queue empty: " << ans.empty() << endl;
    ans.push(420);
    ans.push(34);
    cout << "Size of Queue: " << ans.size() << endl;

}