#include <limits.h>
#include <stdio.h>

int main()
{
    // Problem 02: Find the sum of all the elements of the array
    int array[10] = {2, 4, 2, 5, 7, 10, 12, 3, 0, 1}, sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum = sum + array[i];
    }
    printf("The sum of the elements of the array is: %d", sum);
}