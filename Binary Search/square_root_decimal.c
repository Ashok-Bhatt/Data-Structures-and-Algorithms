#include <stdio.h>

float findPreciseRoot(int num, int precision){
    
    float decimalPlace = 1;
    int root = findRoot(num);
    float ans = root;

    for (int i=0; i<precision; i++){
        decimalPlace = decimalPlace/10.0;

        for (float i=decimalPlace; i<=decimalPlace*10; i=i+decimalPlace){
            if ((ans+i)*(ans+i)>num){
                ans = ans+i-decimalPlace;
                break;
            }
        }
    }
    return ans;  
}

int main(void) {

    int num;
    printf("Enter number: ");
    scanf("%d",&num);

    int precision = 3;
    float root2 = findPreciseRoot(num,precision);
    printf("\nSquare root of %d to %d digits: %f", num, precision, root2);
    
    return 0;
}