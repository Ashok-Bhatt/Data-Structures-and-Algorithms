#include <stdio.h>

int findUnique(int arr[], int n){
    int ans = 0;
    for (int i=0; i<n; i++){
        ans = ans^arr[i];
    }
    return ans;
}

int main(void) {
    int array1[10] = {4,6,5,5,2,6,4};
    int ans1 = findUnique(array1, 7);
    printf("\nUnique Element: %d",ans1);
    return 0;
}