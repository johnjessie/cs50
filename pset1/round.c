#include <cs50.h>
#include <stdio.h>
#include <math.h>

int
main(void)
{
	printf("Enter a float with a few decimal places: ");
	int change = (int) round(GetFloat() * 100);
	printf("change equals: %d", change);
}
