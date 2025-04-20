#include <bits/stdc++.h>
using namespace std;

int main(){

    int arr[] = {1,4,0,-6};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i=0; i<n; i++) {
        printf("~(%d) = %d \n", arr[i], ~arr[i]);
    }

    return 0;
}