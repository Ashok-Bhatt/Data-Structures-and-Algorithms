#include <stdio.h>

int findDuplicate(int arr[],int n){
    int sum=0;
    for (int i=0; i<n; i++){
        sum = sum+arr[i];
    }

    int ans = sum-(n)*(n-1)/2;
    return ans;
}

int main(void) {
    int array[10] = {7,4,2,6,1,3,5,7,8,9};
    int ans = findDuplicate(array, 10);
    printf("Duplicate Element: %d",ans);
    return 0;
}