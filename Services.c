/*
 * Services.c
 *
 *  Created on: May 21, 2018
 *      Author: tiger
 */

#include <stdio.h>
#include <string.h>
#include "Services.h"

//*****************************************************************************************************************
//*********************************************SEARCHING ALOG******************************************************
//*****************************************************************************************************************

int LinearSearhing ( int *search , int data  , int size)
{
	int rc = 0;
	for (int index = 0; index < size ; index ++)
	{
		if (data == search[index])
		{
			rc = index;
		}
	}
	rc = -1;
	return rc;
}

int binarySearch(int *arr, int First_index, int Last_index, int Data)
{
	if (Last_index >= First_index)
	{
		int mid = First_index + (Last_index - First_index)/2;

		// If the element is present at the middle
		// itself
		if (arr[mid] == Data)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > Data)
			return binarySearch(arr, First_index, mid-1, Data);

		// Else the element can only be present
		// in right subarray
		return binarySearch(arr, mid+1, Last_index, Data);
	}

	// We reach here when element is not
	// present in array
	return -1;
}

int interpolationSearch(int *arr, int size, int Data)
{
	// Find indexes of two corners
	int lo = 0, hi = (size - 1);

	// Since array is sorted, an element present
	// in array must be in range defined by corner
	while (lo <= hi && Data >= arr[lo] && Data <= arr[hi])
	{
		// Probing the position with keeping
		// uniform distribution in mind.
		int pos = lo + (((double)(hi-lo) /
				(arr[hi]-arr[lo]))*(Data - arr[lo]));

		// Condition of target found
		if (arr[pos] == Data)
			return pos;

		// If x is larger, x is in upper part
		if (arr[pos] < Data)
			lo = pos + 1;

		// If x is smaller, x is in lower part
		else
			hi = pos - 1;
	}
	return -1;
}

//*****************************************************************************************************************
//**************************************************SWAP***********************************************************
//*****************************************************************************************************************

//Swap using 3 variable
void swap_3(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

//Swap using 2 variable
void swap_2(int *x , int *y)
{
	*x = (*x)^(*y);
	*y = (*x)^(*y);
	*x=  (*x)^(*y);
}

//*****************************************************************************************************************
//***********************************************SORTING ALOG******************************************************
//*****************************************************************************************************************

void selectionSort(int *arr, int size)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < size-1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i+1; j < size; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element
		swap_2(&arr[min_idx], &arr[i]);
	}
}

void bubbleSort(int *arr, int size)
{
    // Base case
    if (size == 1)
        return;

    // One pass of bubble sort. After
    // this pass, the largest element
    // is moved (or bubbled) to end.
    for (int i=0; i<size-1; i++)
        if (arr[i] > arr[i+1])
            swap_2(&arr[i], &arr[i+1]);

    // Largest element is fixed,
    // recur for remaining array
    bubbleSort(arr, size-1);
}

void insertionSort(int *arr, int size)
{
   int i, key, j;

   for (i = 1; i < size; i++)
   {
       key = arr[i];
       j = i-1;

       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}
