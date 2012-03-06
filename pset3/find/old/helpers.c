/**************************************************************************** 
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 ***************************************************************************/
       
#include <cs50.h>

#include "helpers.h"


/*
 * bool
// * search(int value, int array[], int n)
 *
 * Returns true if value is in array of n values, else false.
 */
bool
search(int value, int array[], int first, int last)
{
    // TODO: re-implement as binary search
	int middle = last / 2;
	if ( value == array[middle] )
		return true;
	if ( first == last && value != array[middle] )
		return false;
	else if ( value > array[middle] )
		return search(value, array, (int) middle, last);
	else if ( value < array[middle] )
		return search(value, array, (int) first, middle);
	return false;
}


/*
 * void
 * sort(int values[], int n)
 *
 * Sorts array of n values.
 */

void 
sort(int values[], int n)
{
    // TODO: implement an O(n^2) sort
	// Bubble sort method.
	int i, holder;
	if ( n > 0 )
	{
		for ( i = 0; i < (n - 2); i++ )
		{
			int first = values[i];
			int second = values[i + 1];
				if ( second >= first )
				{
					holder = first;
					first = second;
					second = holder;
				}
		}
		return sort(values, (n - 1) );
	}
}

void Bubblesort(int* elements, int length){
int i;
	   
if(length > 0){
for(i=0;i<length;i++){
int first = elements[i];
int second = elements[i+1]; 

if(second < first){
// Swap
int tmp = elements[i+1];
elements[i+1] = elements[i];
elements[i] = tmp;
}
}

// Recursive call
Bubblesort(elements,length-1);
}
}
