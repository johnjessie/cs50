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
search(int value, int array[], int n)
{
    // TODO: re-implement as binary search
	// DONE: unable to be recursive while 
	// staying within prototype restraints :(
	// so this is iterative
	int low, high, mid;
	
	low = 0; high = n - 1;
	while (low <= high)
	{
		mid = ( low + high ) / 2;
		if ( value == array[mid] )
			return true;
		if (value < array[mid] )
			low = mid - 1;
		else
			low = mid + 1;
	}
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
	int i, j, temp;
	if ( n > 0 )
	{
		for ( i = 0; i < ( n - 1 ); i++ )
		{
			for ( j = 1; j <= i; j++ )
			{
				if ( values[j - 1] > values[j] )
				{
					temp = values[j - 1];
					values[j - 1] = values[j];
					values[j] = temp;
				}
			}
		}
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
