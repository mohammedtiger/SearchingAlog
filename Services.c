/*
 * Services.c
 *
 *  Created on: May 21, 2018
 *      Author: tiger
 */

#include <stdio.h>
#include <string.h>
#include "Services.h"


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
