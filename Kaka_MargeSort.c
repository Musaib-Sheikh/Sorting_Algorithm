#include<stdio.h>
#include <stdlib.h>
void merge(int arr[], int low, int middle, int high);
void mergeSort(int arr[], int low, int high);
int main(){
  // int unsortedArray[]= {2, 3, 34, 23, 19, 44, 38, 1, 17, 76};

  // Start-----------1 lak Array element initializing----------------------------
  int size = 100000;
  int count=0;
  int *unsortedArray = (int *)malloc(size * sizeof(int));

  FILE *file = fopen("numbers.txt", "r");
  if (file == NULL) {
        printf("numbers.txt not found!\n");
        free(unsortedArray);
        return 1;
    }
  for (int i = 0; i < size; i++) {
        fscanf(file, "%d", &unsortedArray[i]);
    }
  fclose(file);
// End-----------1 lakh Array element initializing---------------------------------

//  Start--------------Sorting Algorithom-------------------------
  // int arraySize= sizeof(unsortedArray)/ sizeof(unsortedArray[0]);
  int arraySize= size;
  mergeSort(unsortedArray, 0, arraySize-1);
  printf("Array size: %d\nSorted Array: ", arraySize);
  for(int i=0; i< arraySize; i++){
    printf("%d  ", unsortedArray[i]);
    count++;
  }
//  End--------------Sorting Algorithom---------------------------
// total output checker
printf("\ntotal output: %d", count);
  free(unsortedArray);
  return 0;
}
// Start--------------------------merge() funciton--------------------
void merge(int arr[], int low, int middle, int high){
  int leftPointer, rightPointer, tempArrayPointer;
  leftPointer= low;
  rightPointer= middle+1;
  tempArrayPointer= 0;
  int tempArray[high - low + 1];
  while(leftPointer <= middle && rightPointer <= high){
    if(arr[leftPointer] < arr[rightPointer]){
      /****************< or >*******************
       * full program thik kore ****************** */
      tempArray[tempArrayPointer]= arr[leftPointer];
      tempArrayPointer++;
      leftPointer++;
    }
    else {
      tempArray[tempArrayPointer]= arr[rightPointer];
      tempArrayPointer++;
      rightPointer++;
    }
    }
    while(leftPointer<= middle){
      tempArray[tempArrayPointer]= arr[leftPointer];
      tempArrayPointer++;
      leftPointer++;
    }
    while(rightPointer<= high){
      tempArray[tempArrayPointer]= arr[rightPointer];
      tempArrayPointer++;
      rightPointer++;
    }
    for(int i=low, tempArrayPointer=0; i<=high; i++, tempArrayPointer++ ){
      arr[i]= tempArray[tempArrayPointer];
    }
  }
// End--------------------------merge() funciton----------------------

// Start--------------------------mergeSort() funciton-------------------
void mergeSort(int arr[], int low, int high){
  if(low >= high)return;
  int middle= low+ (high-low)/2;
    mergeSort(arr, low, middle);
    mergeSort(arr, middle+1, high);
    merge(arr, low, middle, high);
}
// End--------------------------mergeSort() funciton----------------------
