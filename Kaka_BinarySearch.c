/*This program is deigned to find out a particular number  from a particular array using binary search method*/
// Alert!! binary search will only applicable when array elements are sorted
// otherwise we have to use linear search
#include<stdio.h>
#define expect 97
int binarySearch(int arr[], int size, int find);
int main(){
	int binarySearchArray[10]= {5, 8, 12, 25, 32, 40, 45, 80, 89, 97};
	int arrSize= sizeof(binarySearchArray)/ sizeof(binarySearchArray[0]);
	int NumberOfExpect= binarySearch(binarySearchArray, arrSize, expect);

	(NumberOfExpect==-1) ? 
	printf("The number is not present in Database."): printf("%d is in no: %d", expect, NumberOfExpect+1);

	return 0;
}
int binarySearch(int arr[], int size, int find){
	int r= size-1;
	int l= 0; // primary initialization of r & l

	while(l<=r) // loop will run untill left side (l) and right side (r) are equal
	{
		int middle= (l+r)/ 2; // finding middle point	of array //
	// অধিক নিরাপদ পদ্ধতি (Integer Overflow এড়াতে): int middle = l + (r - l) / 2;

	if(arr[middle]== find)return middle;
	(arr[middle]> find)? 
	(r= middle-1): (l= middle+1); // r & l update 
	}

	return -1; // if ecpected number is not found
}

