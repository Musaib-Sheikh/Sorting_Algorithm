// This program uses quick sort for sorting an unsorted array's element
#include <stdio.h>

void quickSort(int arr[], int lower, int high);

int Partition_and_PivotDeterminer(int arr[], int lower, int high);

int main()
{

  int unsortedArray[] = {2, 3, 78, 22, 35, 12, 8};

  // Determine Array Size
  int arraySize = sizeof(unsortedArray) / sizeof(unsortedArray[0]);
  //---------------------

  // Print array element before sorting
  printf("Before sorting: ");
  for (int i = 0; i < arraySize; i++)
  {
    printf("%d ", unsortedArray[i]);
  }
  printf("\n");
  //-----------------------------------

  // Sort array element using "Quick sort" method
  quickSort(unsortedArray, 0, arraySize - 1);
  //--------------------------------------------

  // Print array element after sorting
  printf("After sorting: ");
  for (int i = 0; i < arraySize; i++)
  {
    printf("%d ", unsortedArray[i]);
  }
  //----------------------------------
  return 0;
}

// Quick Sort Function
void quickSort(int arr[], int lower, int high)
{
  if (lower < high)
  {
    // storing new pivot index in "pivot" variable
    // Pivot-এর সঠিক position বের করা
    int PIVOTindex = Partition_and_PivotDeterminer(arr, lower, high);
    // left side sorting
    //  Pivot-এর বাম পাশ sort করা
    quickSort(arr, lower, PIVOTindex - 1);
    // right side sorting
    // Pivot-এর ডান পাশ sort করা
    quickSort(arr, PIVOTindex + 1, high);
  }
}

// Function for Partition on both side of "Pivot" and determine new "Pivot index"
int Partition_and_PivotDeterminer(int arr[], int lower, int high)
{
  int i = lower - 1;
  for (int j = lower; j < high; j++)
  {
    if (arr[j] < arr[high])
    {
      i++;
      int temp = arr[j];
      arr[j] = arr[i];
      arr[i] = temp;
    }
  }
  // placing new pivot by swaping between "old pivot(arr[high])" and "arr[i+1]"
  // Pivot-কে সঠিক position-এ বসানো
  int temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;

  // return pivot index to "quickSort" functoin in "pivot" variable
  return i + 1;
}