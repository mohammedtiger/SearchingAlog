/*
 * Services.h
 *
 *  Created on: May 21, 2018
 *      Author: tiger
 */

#ifndef SERVICES_H_
#define SERVICES_H_

void read_scanf_name(char *name , int size);
int LinearSearhing ( int *search , int data  , int size);
int binarySearch(int *arr, int First_index, int Last_index, int Data);
int interpolationSearch(int *arr, int size, int Data);


void swap_3(int *xp, int *yp);
void swap_2(int *x, int *y);


void selectionSort(int *arr, int size);
void bubbleSort(int *arr, int size);


#endif /* SERVICES_H_ */
