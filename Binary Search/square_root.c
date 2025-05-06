#include <stdio.h>

int findRoot(int num){
    int s=1, e = num, m;
    int ans=0;
    while (s<=e){
        m = s+(e-s)/2;
        if (m*m==num)
            return m;
        else if (m*m>num)
            e = m-1;
        else{
            ans = m;
            s = m+1;
        }     
    }

    return ans;
}

int main(void) {

    int num;
    printf("Enter number: ");
    scanf("%d",&num);

    int root1 = findRoot(num);
    printf("\nSquare root of %d: %d",num,root1);
    
    return 0;
}