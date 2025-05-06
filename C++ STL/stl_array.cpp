#include <array>
#include <iostream>
using namespace std;

int main() {

  array<int, 6> arr = {1, 4, 2, 4, 25, 0};

  // Length of array
  cout << arr.size() << endl;

  // Front element of array
  cout << arr.front() << endl;

  // Back element of array
  cout << arr.back() << endl;

  // Returns element at provided index
  cout << arr.at(4) << endl;

  // Is array empty?
  cout << arr.empty() << endl;
}