#include <stdio.h>

int sort(int values[], int n);

int
main(void)
{
	int mylist[5] = {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; i++)
		printf("%d,", mylist[i]);
	sort(&mylist, 5);
	for (int j = 0; j < 5; j++)
		printf("%d,", mylist[j]);
}
int
sort(int values[], int n)
{
	int i, holder, swapctr;
    // TODO: implement an O(n^2) sort
	// Bubble sort method.
	// this is an inverted bubble sort
	// bubbling biggest to bottom
	// is length(n) bigger than 0?
	// if so do stuff. else don't do stuff
	if ( n > 0 )
	{
		swapctr = 0;
		// walk over list
		for ( i = 0; i < (n - 1); i++ )
		{
			// store loop counter position of
			// array at first and loop+1 at
			// second
			int first = (int) values[i];
			int second = (int) values[i + 1];
				// if second is bigger swap
				if ( second > first )
				{
					holder = first;
					second = first;
					first = holder;
					// increment swap counter
					swapctr++;
				}
				// else repeat loop
		}
		// check swap counter, if no swaps recurse
		if ( swapctr == 0 )
			// call ourselves with length(n) decremented
			return sort(values, (n - 1) );
	}
	return values;
}
