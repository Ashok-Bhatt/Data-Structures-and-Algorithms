#include <stdio.h>

int main(void) {
    
// Problem 01: Binary search implementation:
  int array1[100], size;
  printf("Enter the number of array elements:");
  scanf("%d",&size);
  printf("\nEnter the array elements in increasing order:\n");
  for (int i=0; i<size; i++){
      scanf("%d",&array1[i]);
  }

  int start=0, end=size-1, mid=start+(end-start)/2, key, flag=0;
  printf("\nEnter the key:");
  scanf("%d",&key);
  while (start<=end){
      if (array1[mid]==key){
          printf("\nThe index of %d is %d", key, mid);
          flag = 1;
          break;
      }
      else if(array1[mid]<key){
          start = mid+1;
      }
      else if(array1[mid]>key){
          end = mid-1;
      }
      mid=start+(end-start)/2;
  }

  if (flag==0){
      printf("\n%d is not present in an array.",key);
  }
}