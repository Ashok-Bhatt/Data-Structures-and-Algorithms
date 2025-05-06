#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

    vector<int> v;
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(3);
    v.push_back(11);
    v.push_back(51);

    cout << "Is there 1: " << binary_search(v.begin(), v.end(), 1) << endl;

    cout << "Lower bound: " << lower_bound(v.begin(), v.end(), 11) - v.begin() << endl;

    cout << "Upper bound: " << upper_bound(v.begin(), v.end(), 11) - v.begin() << endl;

    int a=6, b=3;
    cout << endl << "a = " << a << "  and  b = " << b << endl;;
    cout << "Maximum Element: " << max(a,b) << endl;
    cout << "Minimum Element: " << min(a,b) << endl;
    swap(a,b);
    cout << "a = " << a << "  and  b = " << b << endl;

    
    string str = "abcdefg";
    
    cout << endl << "String before reversing: " << str;
    reverse(str.begin(), str.end()-2);
    cout << endl << "String before reversing: " << str << endl;


    cout << endl << "Vector before rotation: " << endl;
    for (int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    
    rotate(v.begin(), v.begin()+1, v.end());
    
    cout << endl << "Vector after rotation: " << endl;
    for (int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    sort(v.begin(),v.end());
    cout << endl << "Vector after sorting: " << endl;
    for (int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    
}